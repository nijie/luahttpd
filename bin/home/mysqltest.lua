require "index"

mysqltest = {}

function mysqltest.get(h)
	local q = DBAsk:new()
	q:setSQL('luahttpd', 'select * from user;')
	AddAsk(h, q, mysqltest.onQuery)
	print ('select * from user;\r\n')
end

function mysqltest.onQuery(h, d, r)
	print(h)
	print(d)
	print(r)
	if (not d:begin()) then
		print('select failed')
	end
	
	while (d:next()) do
		print ('first : '..d:get(0)..' second : '..d:get(1))
	end
	
	local q = DBAsk:new()
	q:setSQL('luahttpd2', 'insert into user2(id2, name2) values(1, "adkfjkajdfkjadksf")')
	AddAsk(h, q)
	
	print('nijie test mysql query')
end