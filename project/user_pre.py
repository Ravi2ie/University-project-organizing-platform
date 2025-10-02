from flask import Flask, request, render_template, send_file
import subprocess

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('user_feedback.html')

@app.route('/checkProject')
def check_project():
    try:
        # Run C++ program to prioritize feedback data
        result = subprocess.check_output(['./user_premium']).decode().strip()
        return result
    except subprocess.CalledProcessError:
        return "Error: Failed to prioritize feedback data."

if __name__ == '__main__':
    app.run(port=5001, debug=True)  # Running on port 5001
