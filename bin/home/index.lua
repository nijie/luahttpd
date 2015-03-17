function print_r (o, indent)
	indent = indent or 0
	local szSuffix = ""
	if type(o) == "table" then
		szSuffix = "{"
	end
	local szPrefix = string.rep("    ", indent)
	formatting = szPrefix..szSuffix
	if type(o) == "table" then
		print(formatting)
		for k, v in pairs(o) do
			if type(k) == "string" then
				k = string.format("%q", k)
			end
			local szPrefix = string.rep("    ", indent)
			--formatting = szPrefix.."["..k.."]".." = "
			formatting = szPrefix..k.." : "
			if type(v) == "table" then
				print(formatting)
				--print_r(v, indent + 1)
				--print(szPrefix.."},")
			else
				local szValue = ""
				if type(v) == "string" then
					szValue = string.format("%q", v)
				else
					szValue = tostring(v)
				end
				print(formatting..szValue..",")
			end
		end
	else
		local szValue = ""
		if type(o) == "string" then
			szValue = string.format("%q", o)
		else
			szValue = tostring(o)
		end
		print(formatting..szValue..",")
	end
end

function index(h)
    local o = {"adfdasf", 1, "222", {"ss", "ddd"}, {"a", 11, "111", {"3334", "222"}}}
	print_r(o)
	
	--[[
	local json = JsonEncode(o)
	print(json)
	local a = JsonDecode(json)
	print_r(a)
	
	local b64 = Base64Encode(json)
	print('base64: ' .. b64)
	local b = Base64Decode(b64)
	print('src: ' .. b)
	]]
end

home = {}

function home.index(h)
	local a = {"adfdasf", 1, "3333", {"ss", "ddd"}, {"a", 11, "111", {"3334", "222"}}}
	print_r(a)
end

home.action = {}
function home.action.put(h)
	local b = {"adfdasf", 1, "aaaa222", {"ss", "ddd"}, {"a", 11, "111", {"3334", "222"}}}
	print_r(b)
end