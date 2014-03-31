from flask import Flask
from flask.ext.login import LoginManager
import os.path

app = Flask(__name__)
login_manager = LoginManager()
login_manager.init_app(app)

@app.route('/<path:url>')
@login_required
def page_loader(url):
    print 'Entered page loader'
    abs = '/home/Bipsy/Repos/practice/flask/web/'
    print abs + url
    with open(abs+url, 'rb') as f:
        content = f.read()
        return content

@app.route('/static/img/<path:url>')
@login_required
def image_loader(url):
    print 'Entered image loader'
    abs = '/home/Bipsy/Repos/practice/flask/web/static/img/'
    print abs + url
    with open(abs+url, 'rb') as f:
        content = f.read()
        extension = os.path.splitext(abs+url)[1]
        if extension == '.jpg':
            return (content, 200, {"Content-Type": "image/jpeg"})
        elif extension == '.gif':
            return (content, 200, {"Content-Type": "image/gif"})
        elif extension == '.png':
            return (content, 200, {"Content-Type": "image/png"})
        else:
            return content

@app.route('/static/files/<path:url>')
@login_required
def text_loader(url):
    print 'Entered image loader'
    abs = '/home/Bipsy/Repos/practice/flask/web/static/files/'
    print abs + url
    with open(abs+url, 'rb') as f:
        content = f.read()
        extension = os.path.splitext(abs+url)[1]
        if extension == '.txt':
            return (content, 200, {"Content-Type": "text/plain"})
        elif extension == '.html':
            return (content, 200, {"Content-Type": "text/html"})
        elif extension == '.pdf':
            return (content, 200, {"Content-Type": "application/pdf"})
        else:
            return content

@app.route("/login", methods=["GET", "POST"])
def login():
    form = LoginForm()
    if form.validate_on_submit():
        login_user(user)
        flash("Logged in successfuly.")
        return redirect(url_for("index"))
    return render_template("login.html", form=form)

@app.route("/logout")
@login_required
def logout():
    logout_user()
    return redirect(url_for("index"))

@login_manager.user_loader
def load_user(userid):
    return 5

        

if __name__=='__main__':
    app.run(debug=True)
