import json
print("Opening json") #recovering old data
data = open("./.json/archive.json")

try:

    js = json.loads(data.read())

except:
    print("quiting")
    quit()
data.close()
fwrite = open("./.json/.tempdata.txt","w")

for p in js:
    #print(p)
    fwrite.write(str(p) )
    fwrite.write("\n")
fwrite.close()
