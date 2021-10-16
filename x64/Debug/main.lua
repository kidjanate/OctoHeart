x = 512/2-50/2
y = 512/2-50/2


score = 0


speed = 5

direction = "right"

pathX = {}
pathY = {}

point = {}



function Start()
    Window.ShowConsole()
    generatePoint()
end

t = 0


c1 = 0
c2 = os.clock()

function Update(deltaTime)
    c1 = os.clock()

    delta = c2 - c1
    delta = delta * 10000000
    speed = speed * delta
    print(speed)
    --Player
    CreateObject("cube", x, y, 20, 20, currentRotate)

    for i=1, score do
        tabCount = #pathX
        if  tabCount >= tabCount-i*100 then
            
            CreateObject("cube", pathX[tabCount-i*100], pathY[tabCount-i*100], 20, 20, currentRotate)
        end
        
        
    end

    if direction == "right" then
        x = x + speed
    end

    if direction == "left" then
        x = x - speed
    end

    if direction == "up" then
        y = y - speed
    end

    if direction == "down" then
        y = y + speed
    end

    table.insert(pathX, x)
    table.insert(pathY, y)

    CreateObject("cube", point.x, point.y, 10, 10, currentRotate)

    if x-point.x > -10 and x-point.x < 10 then
        if y-point.y > -10 and y-point.y < 10 then
            generatePoint()
        end
    end

    c2 = os.clock()
end

function generatePoint()
    point = {
        x=math.random(10,502),
        y=math.random(10,502)
    }
    score = score + 1
end


function OnKeyDown(key)
    if key == Input.KeyCode.W then
        direction = "up"
    end

    if key == Input.KeyCode.A then
        direction = "left"
    end

    if key == Input.KeyCode.S then
        direction = "down"
    end

    if key == Input.KeyCode.D then
        direction = "right"
    end
end


function Lerp(from, to, time)
    return from * (1-time) + to * time
end

function tablelength(T)
    local count = 0
    for _ in pairs(T) do count = count + 1 end
    return count
end

local getTimer = os.clock()
local lastTime = 0

function getTime()

	local dt = 0

	if lastTime == 0 then

		lastTime = getTimer

	else	

		local curTime = getTimer
		dt = curTime - lastTime
		lastTime = curTime	

	end	

	return dt

end	

function restart()

	lastTime = 0

end	