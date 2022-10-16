#Opening the emails file to get the emails list to send the email with the curriculum
fhandle = open('emails.txt', 'r')
emails = []
for lines in fhandle:
    emails.append(lines)

fhandle.close()
print (emails)

#Writing the emails already sent
fwrite = open('emails.txt', 'r')
emailsSent = []
for lines in fhandle:
    fwrite.write(lines)

fhandle.close()