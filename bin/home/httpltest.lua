httptest = {}

function httptest.get(http)
	local hask = HttpAsk:new()
	hask:setUrl('http://www.163.com/')
	AddAsk(http, hask, httptest.onBack)
end

function httptest.onBack(http, ask)
	print(http)
	print(ask)
	if (not ask:isOK()) then
	    print('not ok')
    end
	
	print(ask:getResponse())
end
