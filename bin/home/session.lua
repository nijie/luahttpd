require "index"

sessiontest = {}

function sessiontest.put(h)
	session = h:getSession()
	session:set('mytest', 'nijie test session!')
	print('nijie test session put mytest!')
end

function sessiontest.get(h)
	session = h:getSession()
	val = session:get('mytest')
	print('nijie test session get mytest = '..val)
end