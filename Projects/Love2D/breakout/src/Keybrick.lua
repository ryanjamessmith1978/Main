Keybrick = Class{}

function Keybrick:init(x, y)
    -- used for coloring and score calculation
   self.skin = 0
    
    self.x = x
    self.y = y
    self.width = 32
    self.height = 16
    
    -- used to determine whether this brick should be rendered
    self.inPlay = true
end

--[[
    Triggers a hit on the brick, taking it out of play if at 0 health or
    changing its color otherwise.
]]
function Keybrick:hit()
    -- sound on hit
    gSounds['brick-hit-2']:play()

    self.inPlay = false
end

function Keybrick:render()
    if self.inPlay then
        love.graphics.draw(gTextures['main'], gFrames['keybrick'][1], self.x, self.y)
    end
end