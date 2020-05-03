import requests
import pprint # pprint.pprint() == 美麗的 print()

request_data = {"teamid": "10", "name": "Sky Hong", "chalid": "0", "answer": "10980000", "diy": "true"}
 
r = requests.post(
    'https://sitprac.herokuapp.com/records.json', data=request_data)
data = r.json()
pprint.pprint(data)
