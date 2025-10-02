#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class Comment {
public:
    string id;
    string commenter;
    string content;
    vector<Comment> replies;

public:
    Comment(const string& id, const string& commenter, const string& content) 
        : id(id), commenter(commenter), content(content) {}

    void addReply(const Comment& reply) {
        replies.push_back(reply);
    }

    string toJSON(int depth = 0) const {
        ostringstream oss;
        oss << string(depth * 4, ' ') << "{\n";
        oss << string((depth + 1) * 4, ' ') << "\"id\": \"" << id << "\",\n";
        oss << string((depth + 1) * 4, ' ') << "\"commenter\": \"" << commenter << "\",\n";
        oss << string((depth + 1) * 4, ' ') << "\"comment\": \"" << content << "\",\n";
        oss << string((depth + 1) * 4, ' ') << "\"netVotes\": 0,\n";
        oss << string((depth + 1) * 4, ' ') << "\"userVote\": 0,\n";
        oss << string((depth + 1) * 4, ' ') << "\"commenterBan\": false,\n";
        oss << string((depth + 1) * 4, ' ') << "\"children\": [";

        if (!replies.empty()) {
            oss << "\n";
            for (size_t i = 0; i < replies.size(); ++i) {
                oss << replies[i].toJSON(depth + 2);
                if (i != replies.size() - 1) oss << ",";
                oss << "\n";
            }
            oss << string((depth + 1) * 4, ' ');
        }
        oss << "]\n" << string(depth * 4, ' ') << "}";
        return oss.str();
    }
};

class CommentSystem {
private:
    vector<Comment> comments;

public:
    void addComment(const string& id, const string& commenter, const string& content) {
        comments.push_back(Comment(id, commenter, content));
    }

    void addReply(const string& parentId, const string& id, const string& commenter, const string& content) {
        addReplyHelper(comments, parentId, id, commenter, content);
    }

    void addReplyHelper(vector<Comment>& comments, const string& parentId, const string& id, const string& commenter, const string& content) {
        for (auto& comment : comments) {
            if (comment.id == parentId) {
                comment.addReply(Comment(id, commenter, content));
                return;
            }
            addReplyHelper(comment.replies, parentId, id, commenter, content); // Search in replies recursively
        }
    }

    string toJSON() const {
        ostringstream oss;
        oss << "[\n";
        for (size_t i = 0; i < comments.size(); ++i) {
            oss << comments[i].toJSON(1);
            if (i != comments.size() - 1) oss << ",";
            oss << "\n";
        }
        oss << "]";
        return oss.str();
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            file << toJSON();
            file.close();
        } else {
            cerr << "Unable to open file for writing: " << filename << endl;
        }
    }
};

int main() {
    CommentSystem commentSystem;

    commentSystem.addComment("1", "Alice", "This is the first comment.");
    commentSystem.addReply("1", "2", "Bob", "This is a reply to the first comment.");
    commentSystem.addReply("1", "7", "dred", "This is also a reply to the first comment.");
    commentSystem.addReply("7", "2", "Bob", "This is a reply to the first comment.");
    commentSystem.addComment("3", "Charlie", "This is another comment.");
    commentSystem.addReply("3", "4", "Dave", "This is a reply to the second comment.");
    commentSystem.addReply("4", "5", "Dj", "This is a reply to an reply.");
    commentSystem.saveToFile("comments.json");

    return 0;
}
