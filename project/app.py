from flask import Flask, request, render_template, send_file
import subprocess

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/checkProject')
def check_project():
    try:
        # Run C++ program to reverse loan data
        result = subprocess.check_output(['./a.out']).decode().strip()
        return result
    except subprocess.CalledProcessError:
        return "Error: Failed to reverse loan data."

if __name__ == '__main__':
    app.run(debug=True)
