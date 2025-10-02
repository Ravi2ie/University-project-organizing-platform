// Function to recursively extract comments
function extractComments(commentData) {
    let extractedComments = [];
    commentData.forEach(comment => {
        extractedComments.push({
            id: comment.id,
            commenter: comment.commenter,
            comment: comment.comment
        });
        if (comment.children.length > 0) {
            extractedComments = extractedComments.concat(extractComments(comment.children));
        }
    });
    return extractedComments;
}

// Read the JSON file using fetch API
fetch('comments.json') // Accessing the JSON file from the local server
    .then(response => response.json())
    .then(data => {
        const extractedComments = extractComments(data);
        console.log(extractedComments); // Output extracted comments
    });
