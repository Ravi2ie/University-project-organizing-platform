# 🎓 University Project Organizing Platform  

A **comprehensive web & software solution** for managing **university student projects**, built to streamline:  
- **Project allocation** between students and supervisors  
- **Feedback & communication**  
- **Comments & collaboration**  
- **Task prioritization & request handling**  
- **Student–Admin–Faculty coordination**  

This platform provides a **centralized hub** for project management with a mix of **web (Flask, PHP, HTML/JS), C++ executables, and Python scripts** to handle different modules like project allocation, comment management, feedback, and data visualization.  

---

## 📂 Project Structure  

    
    ├── ads_output_2024_team_no_6.zip              # Screenshots & project visuals
    │   ├── admin.png
    │   ├── student.png
    │   ├── projects.png
    │   ├── priority_queue.png
    │   ├── topo_logical.png
    │   └── ... (UI & workflow images)
    
    ├── comment displayer                          # Comment & feedback management system
    │   └── Login & Signup Form
    │       ├── comment.cpp                        # Core C++ logic for comment posting
    │       ├── comments.json                      # Comment storage (JSON format)
    │       ├── css/style.css                      # Styling
    │       ├── index.html                         # Frontend
    │       ├── script.js                          # Client-side logic
    │       └── images/google.png                  # Icons
    
    ├── project                                    # Main web app for project allocation
    │   ├── app.py                                 # Flask backend server
    │   ├── main.cpp                               # C++ allocation logic
    │   ├── getReversedLoanData.php                # Sample PHP backend utility
    │   ├── templates/                             # HTML + project files
    │   │   ├── index.html
    │   │   ├── university_operation.html          # Admin dashboard
    │   │   ├── user_feedback.html                 # Feedback collection page
    │   │   ├── *.txt                              # Stored logs/feedback
    │   ├── user_pre.cpp                           # Student preference manager
    │   ├── user_pre.py                            # Python-based student input handler
    │   └── executables (a.out, *.exe, *.cgi)      # Compiled binaries for utilities
    
    ├── studentprojectallocation.zip               # Packaged project archive
    ├── code_to_database.zip                       # Database connectivity scripts
    ├── comments.json                              # Global comment data
    └── project.zip                                # Compressed version of `project/`


# 📖 About the Project: Streamlining University Student Projects

Universities often struggle with coordinating student projects due to several common challenges:

* **Large Student Groups:** Managing numerous students across various projects simultaneously.
* **Multiple Faculty Supervisors:** Coordinating supervision duties and ensuring equitable workload distribution.
* **Manual Request/Approval Workflows:** Slow, paper-based, or email-dependent processes for project changes and approvals.
* **Inefficient Tracking:** Difficulty monitoring **feedback** and **progress** in a centralized location.

---

## Key Platform Solutions

This platform addresses those issues by introducing a cohesive, automated system:

### **✔ Automated Allocation**
* Automating project allocation using sophisticated **algorithms** (e.g., **priority queue**, **graph/topological sorting**) for optimal pairing.
* Allowing students to submit **project preferences** and receive an **optimized allocation** that attempts to satisfy constraints and fairness.

### **✔ Enhanced Administration**
* Facilitating **admin dashboards** for efficient project approvals, supervisor assignment, and request handling.
* Supporting **student profiles** and **request submissions** (e.g., group changes, topic shifts) for transparency and streamlined processing.

### **✔ Collaboration & Tracking**
* Providing a robust **feedback/commenting system** integrated directly into the project workspace to enhance **collaboration** between students and supervisors.
* Enabling efficient and centralized **tracking** of progress milestones and supervisor feedback.


# ⚙️ Working of the Project

## 🔹 Workflow Overview

The platform operates through a structured, automated cycle to ensure efficient project management and allocation:

### **1. Student Login & Preference Submission**
* **Action:** Students securely sign in to the platform.
* **Input:** They set their **project preferences** (e.g., preferred topics, technologies) and have the option to submit detailed project **proposals**.

### **2. Project Allocation (Algorithmic Core)**
* **Automation:** The backend initiates the core **C++ logic** (`main.cpp`, `user_pre.cpp`) for optimized allocation.
* **Algorithms Used:**
    * **Priority Queue Scheduling:** Used to prioritize high-demand projects or student groups based on defined criteria.
    * **Topological Sorting:** Applied potentially for scheduling tasks within a project or handling **dependency-based** project sequencing.
* **Outcome:** Projects are **fairly allocated** to student groups while balancing the workload across multiple faculty **supervisors**.

### **3. Admin Dashboard & Request Handling**
* **Functionality:** Administrators utilize a centralized dashboard to manage the project lifecycle.
* **Key Actions:** View, **approve**, or **reject** project change requests.
* **Monitoring:** Track student submissions and requests (illustrated by conceptual screens like `request_student.png`, `show_req_admin.png`).

### **4. Feedback & Comment System**
* **Collaboration:** Students and faculty can post **real-time comments** and feedback directly on project pages.
* **Storage:** Comments are lightweight and stored efficiently using **JSON** format.
* **Authentication:** The commenting module allows for live posting and viewing after simple login/signup.

### **5. Reports & Visualization**
* **Illustrations:** Conceptual images (`priority_queue.png`, `topo_logical.png`) are used to visualize the immediate results of the **allocation logic**.
* **History & Logging:** Historical data and important system information are maintained in dedicated log and text files (`prior_feed.txt`, `project.txt`).

---

## 🛠 Tech Stack

The platform utilizes a hybrid technology stack, leveraging the speed of compiled code for the core logic and the flexibility of scripting languages for the web interface:

| Component | Technologies Used | Purpose |
| :--- | :--- | :--- |
| **Frontend** | **HTML, CSS, JavaScript** | Building the user interface and handling client-side interactivity. |
| **Backend** | **Python (Flask), PHP** | Handling server-side logic, routing, and database interactions. |
| **Core Algorithms** | **C++** | The engine for project **allocation**, preference matching, and high-performance processing. |
| **Database/Storage** | **JSON, text-based logs, SQL** (optional) | Storing configuration data, user comments (JSON), historical data, and structured data. |
| **Executables** | **.exe, .cgi, .out** | Compiled modules for running the C++ allocation and feedback processors on the server. |
| **Algorithms** | **Priority Queue, Graph Topology** | The mathematical and computational backbone for intelligent scheduling. |


## 🚀 How to Clone & Run

1. **Clone Repository**

    ```bash
    git clone https://github.com/Ravi2ie/University-project-organizing-platform.git
    cd University-project-organizing-platform


2. **Backend Setup (Flask)**

    ```bash
    cd project
    pip install -r requirements.txt   # (if requirements.txt is present)
    python app.py


3. **Server starts at: http://127.0.0.1:5000/**

4. **Run C++ Modules**

    ```bash
    g++ main.cpp -o main
    ./main


5. **Run Comment System**

    ```bash
    cd "comment displayer/Login & Signup Form"
open index.html  # Or host on localhost


# 💡 Key Features and Enhancements

---

## ✔ Platform Features

The system is designed with distinct capabilities for students, administrators, and the core system logic.

### **Student Features**
* **Access:** Secure **Login/Signup** functionality.
* **Submission:** Ability to submit detailed project **requests** and **preferences**.
* **Tracking:** View their **allocated projects** and associated supervisors.
* **Collaboration:** Post **feedback & comments** directly on project pages.

### **Admin Features**
* **Management:** A dedicated **Dashboard** for handling all incoming student requests and project approvals.
* **Oversight:** Monitor overall **student allocations** and supervisor workloads.
* **Reporting:** View high-level **project trends** and system usage statistics.

### **System Features**
* **Core Logic:** Intelligent **Project Allocation** using advanced algorithms like **Priority Queue** and **Topological Sorting**.
* **Data Handling:** **JSON-based comment saving** for efficient, lightweight storage.
* **Flexibility:** Support for a **hybrid backend** utilizing **Python (Flask), PHP, and C++** to leverage the strengths of each language.
* **Speed:** Use of **Executable utilities** (`.exe`, `.out`) for faster execution of core allocation and processing tasks.

---

## 📊 Screenshots (Examples)

*(These conceptual images are assumed to be located in the `ads_output_2024_team_no_6/` folder.)*

| Dashboard | Example Image | Description |
| :--- | :--- | :--- |
| **🧑‍🎓 Student Dashboard** | `student.png` | Main view for students to check allocations and submit preferences. |
| **👨‍🏫 Admin Dashboard** | `admin.png`, `admin_req.png` | Admin view for system oversight and managing approval/rejection requests. |
| **📈 Project Allocation** | `priority_queue.png`, `topo_logical.png` | Visual representation of the allocation logic output and efficiency. |
| **💬 Comment Section** | `comment.png` | Interface for students and faculty to post and view project feedback. |

---

## 🔮 Future Enhancements

The roadmap includes significant upgrades to enhance reliability, interactivity, and scalability:

* **Database Upgrade:** Replace current JSON/text file storage with a full **SQL Database** for better data integrity and querying.
* **Real-Time Communication:** Add **real-time notifications** for project approvals, rejections, and new comments.
* **Scalability:** Expand the platform to support **multi-department universities** with complex cross-college requirements.
* **Advanced Analytics:** Introduce a dedicated **analytics dashboard** to track project success rates, supervisor load balance, and student satisfaction.

## 🤝 Contributing

Contributions are welcome! 🚀

1. **Fork the repository**

2. **Create a new branch**

    ```bash
    git checkout -b feature-name


3. **Commit changes**

    ```bash
    git commit -m "Added new feature"


4. **Push to branch**

    ```bash
    git push origin feature-name


5. **Create a Pull Request**
