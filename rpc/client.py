import xmlrpclib

s = xmlrpclib.ServerProxy('http://localhost:8000')
print s.pow(2,3)
print s.add(2,3)
print s.div(5,2)

print s.system.listMethods()
