from flask import Flask, g, session, redirect, url_for, request
from flask import render_template
from flask_oauthlib.client import OAuth

app = Flask(__name__)
oauth = OAuth(app)

twitter = oauth.remote_app('twitter',
	base_url='https://api.twitter.com/1.1/',
	request_token_url='https://api.twitter.com/oauth/request_token',
	access_token_url='https://api.twitter.com/oauth/access_token',
	access_token_method='POST',
	authorize_url='https://api.twitter.com/oauth/authenticate',
	consumer_key='xBeXxg91yE1UgwZT6AZ0A',
	consumer_secret='aawnSpNTOVuDCjx7HMh6uSXetjNN8zWLpZwCEU4LBrk'
)

@app.before_request
def before_request():
	g.user = None
	if 'twitter_oauth' in session:
		g.user = session['twitter_oauth']

@app.route('/')
def home():
	tweets = None
	if g.user is not None:
		resp = twitter.request('statuses/home_timeline.json')
		if resp.status == 200:
			tweets = resp.data
		else:
			flash('Unable to load tweets from Twitter.')
	return render_template('index.html', tweets=tweets)

@app.route('/tweet', methods=['POST'])
def tweet():
	if g.user is None:
		return redirect(url_for('login', next=request.url))
	status = request.form['tweet']
	if not status:
		return redirect(url_for('index'))
	resp = twitter.post('statuses/update.json', data={
		'status': status
	})
	if resp.status == 403:
		flash('Your tweet was too long.')
	elif resp.status == 401:
		flash('Authorization error with Twitter.')
	else:
		flash('Successfully tweeted your tweet (ID: #%s)' % resp.data['id'])
	return redirect(url_for('index'))

@app.route('/login')
def login():
	return twitter.authorize(callback=url_for('twitter_authorized',
			next=request.args.get('next') or request.referrer or None,
			_external=True))

@app.route('/logout')
def logout():
	session.pop('twitter_oauth', None)
	return redirect(url_for('index'))

@app.route('/twitter_authorized')
@twitter.authorized_handler
def twitter_authorized(resp):
	if resp is None:
		flash(u'You denied the request to sign in.')
	else:
		session['twitter_oauth'] = resp
	return redirect(url_for('index'))



@twitter.tokengetter
def get_twitter_token(token=None):
	if 'twitter_oauth' in session:
		resp = session['twitter_oauth']
		return resp['oauth_token'], resp['oauth_token_secret']

if __name__ == '__main__':
	app.run(debug=True)
