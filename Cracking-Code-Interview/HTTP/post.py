import requests
import json

# URL of the API endpoint
url = "https://api.example.com/create"

# Data to be sent in the POST request (as JSON)
data = {
    "name": "John Doe",
    "email": "john@example.com",
    "age": 30
}

# Convert the data to JSON format
json_data = json.dumps(data)

# Set the headers for the request
headers = {
    "Content-Type": "application/json"
}

# Send the POST request
response = requests.post(url, data=json_data, headers=headers)

# Check the response
if response.status_code == 201:  # HTTP 201 Created
    print("Data successfully created!")
else:
    print("Failed to create data. Status code:", response.status_code)
    print("Response content:", response.content)

