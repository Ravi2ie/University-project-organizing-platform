<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Reversed Loan Data</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f4f4f4;
        }
        h1 {
            text-align: center;
            padding: 20px 0;
        }
        table {
            width: 80%;
            margin: 20px auto;
            border-collapse: collapse;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            background-color: #fff;
        }
        th, td {
            padding: 10px;
            border: 1px solid #ccc;
        }
        th {
            background-color: #f2f2f2;
        }
        .available {
            color: green;
        }
        .unavailable {
            color: red;
        }
        tr:nth-child(even) {
            background-color: #f9f9f9;
        }
        @media screen and (max-width: 600px) {
            table {
                width: 100%;
            }
            th, td {
                font-size: 14px;
            }
        }
    </style>
</head>
<body>
    <h1>Reversed Loan Data</h1>
    <table>
        <thead>
            <tr>
                <th>Project Name</th>
                <th>Project Case</th>
                <th>Project Level</th>
                <th>Allocation Status</th>
            </tr>
        </thead>
        <tbody>
            <?php
            // Define the path to the reversed loan data file
            $filePath = "C:/Users/bhusb/OneDrive/Documents/project/templates/reverse_project.txt";
            
            // Check if the file exists and is readable
            if (file_exists($filePath) && is_readable($filePath)) {
                // Open the file for reading
                $file = fopen($filePath, "r");
                
                // Read the file line by line
                while (($line = fgets($file)) !== false) {
                    // Split the line by commas
                    $data = explode(",", $line);
                    
                    // Trim whitespace from each data field
                    $projectName = trim($data[0]);
                    $projectCase = trim($data[1]);
                    $projectLevel = trim($data[2]);
                    $allocationStatus = trim($data[3]);
                    
                    // Determine the CSS class for the allocation status
                    $allocationClass = (strcasecmp($allocationStatus, 'available') == 0) ? 'available' : 'unavailable';
                    
                    // Output the data in table rows
                    echo "<tr>";
                    echo "<td>" . htmlspecialchars($projectName) . "</td>";
                    echo "<td>" . htmlspecialchars($projectCase) . "</td>";
                    echo "<td>" . htmlspecialchars($projectLevel) . "</td>";
                    echo "<td class='$allocationClass'>" . htmlspecialchars($allocationStatus) . "</td>";
                    echo "</tr>";
                }
                
                // Close the file
                fclose($file);
            } else {
                echo "<tr><td colspan='4'>Error: Unable to read file.</td></tr>";
            }
            ?>
        </tbody>
    </table>
</body>
</html>
