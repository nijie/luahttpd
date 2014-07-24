require "index"

cookietest = {}

function cookietest.put(h)
	h:setCookie('mytest', 'nijie_test_cookie')
	h:setCookie('mytest1', 'nijie_test_cookie00')
	print('nijie test cookie put mytest!')
end

function cookietest.get(h)
	val = h:getCookie('mytest')
	print('nijie test cookie get mytest = '..val)
end