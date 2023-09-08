import requests
import json

# URL of the API endpoint
url = "https://api.example.com/update/123"  # Assuming "123" is the resource identifier

# New data to be sent in the PUT request (as JSON)
new_data = {
    "name": "Updated Name",
    "email": "updated@example.com"
}

# Convert the new data to JSON format
json_data = json.dumps(new_data)

# Set the headers for the request
headers = {
    "Content-Type": "application/json"
}

# Send the PUT request
response = requests.put(url, data=json_data, headers=headers)

# Check the response
if response.status_code == 200:  # HTTP 200 OK
    print("Data successfully updated!")
else:
    print("Failed to update data. Status code:", response.status_code)
    print("Response content:", response.content)
