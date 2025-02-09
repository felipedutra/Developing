import subprocess


result = subprocess.run(['python3', 'web.py'], stdout=subprocess.PIPE)
result = subprocess.run(['python3', 'excel.py'], stdout=subprocess.PIPE)