import os


from datetime import datetime
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash


# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

@app.after_request
def after_request(response):
    #response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    #response.headers["Expires"] = 0
    #response.headers["Pragma"] = "no-cache"
    return response



@app.route("/")
def index():
    return render_template("index.html")

@app.route("/register")
def register():
    if(request.method == "POST"):
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        if not username:
            return confirm("ユーザーネームを登録してください")

@app.route("/index")
def index():
    return render_template("index.html")

@app.route("/home")
def home():
    return render_template("home.html")

@app.route("/create")
def create():
    return render_template("create.html")

@app.route("/detail/<int:id>")
def read(id):
    post = Post.query.get(id)
    return render_template("detail.html", post=post)

@app.route("/delete/<int:id>")
def delete(id):
    post = Post.query.get(id)

    db.session.delete(post)
    db.session.commit()
    return redirect("/")


if __name__=="__main__":
    app.run_server(debug=True)

