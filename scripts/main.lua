local co = coroutine

game = {
	running = true
}

function wait(seconds)
	local now = os.clock
	local time = now() + seconds
	while(now() < time) do
		co.yield()
	end
end

function say(text, step)
	step = step or 0.3
	for i = 1, #text do
		local c = text:sub(i,i)
		io.write(c)
		wait(step)
	end
	print()
end

local func = co.create(
	function()
		say("ciao a tutti")
		say("ragazzi come va?")
	end
)

function main()
	-- UPDATE
	while(game.running) do
		local dt = co.yield()
		if co.status(func) == "dead" then break end
		co.resume(func)
	end
end
