import requests

# URL of the API endpoint
url = "https://api.example.com/delete/123"  # Assuming "123" is the resource identifier

# Send the DELETE request
response = requests.delete(url)

# Check the response
if response.status_code == 204:  # HTTP 204 No Content
    print("Data successfully deleted!")
elif response.status_code == 404:  # HTTP 404 Not Found
    print("Resource not found. Data may have already been deleted.")
else:
    print("Failed to delete data. Status code:", response.status_code)
    print("Response content:", response.content)
