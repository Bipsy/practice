from flask import Flask
from flask.ext.pymongo import PyMongo

app = Flask(__name__)
app.config['MONGO_PORT'] = 27017
mongo = PyMongo(app)

@app.route('/')
def home_page():
	mongo.db.users.remove()
	mongo.db.users.insert({'name': 'John', 'age': 30})
	mongo.db.users.insert({'name': 'Bobby', 'age': 35})
	users = mongo.db.users.find({'age': 31})
	print users
	return str(users.count())

if __name__ == '__main__':
	app.run(debug=True)
