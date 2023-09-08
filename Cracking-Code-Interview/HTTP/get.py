import requests

# URL of the API endpoint
url = "https://api.example.com/data"

# Send the GET request
response = requests.get(url)

# Check the response
if response.status_code == 200:  # HTTP 200 OK
    data = response.json()  # Assuming the response is in JSON format
    print("Received data:", data)
else:
    print("Failed to retrieve data. Status code:", response.status_code)
    print("Response content:", response.content)
