
Powerup = Class{}

function Powerup:init(x, y, skin)
    -- used for coloring and score calculation
    self.skin = skin
    
    self.x = x
    self.y = y
    self.width = 16
    self.height = 16
    self.dy = 20
    
    -- used to determine whether this brick should be rendered
    self.inPlay = true
end

function Powerup:update(dt)

    self.y = self.y + self.dy * dt
end

function Powerup:collides(target)
    -- first, check to see if the left edge of either is farther to the right
    -- than the right edge of the other
    if self.x > target.x + target.width or target.x > self.x + self.width then
        return false
    end

    -- then check to see if the bottom edge of either is higher than the top
    -- edge of the other
    if self.y > target.y + target.height or target.y > self.y + self.height then
        return false
    end 

    -- if the above aren't true, they're overlapping
    return true
end

--[[
    Triggers a hit on the brick, taking it out of play if at 0 health or
    changing its color otherwise.
]]
function Powerup:hit()
    -- sound on hit
    gSounds['brick-hit-2']:play()

    self.inPlay = false
end

function Powerup:render()
    if self.inPlay then
        love.graphics.draw(gTextures['main'], gFrames['power'][self.skin], self.x, self.y)
    end
end