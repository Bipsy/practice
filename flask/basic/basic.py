import Flask

app = Flask(__name__)


@app.route('/')
def index():
	return 'Index page'

@app.route('/login')
def login():
	return 'Login page'

@app.route('/logout')
def logout():
	return 'Logout page'








if __name__ == '__main__':
	app.run(debug=True)
