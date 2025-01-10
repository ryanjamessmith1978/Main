--[[
    GD50
    Match-3 Remake

    -- Tile Class --

    Author: Colton Ogden
    cogden@cs50.harvard.edu

    The individual tiles that make up our game board. Each Tile can have a
    color and a variety, with the varietes adding extra points to the matches.
]]

Tile = Class{}

paletteColors = {
    -- blue
    [1] = {
        ['r'] = 99,
        ['g'] = 155,
        ['b'] = 255
    },
    -- green
    [2] = {
        ['r'] = 106,
        ['g'] = 190,
        ['b'] = 47
    },
    -- red
    [3] = {
        ['r'] = 217,
        ['g'] = 87,
        ['b'] = 99
    },
    -- purple
    [4] = {
        ['r'] = 215,
        ['g'] = 123,
        ['b'] = 186
    },
    -- gold
    [5] = {
        ['r'] = 251,
        ['g'] = 242,
        ['b'] = 54
    }
}

function Tile:init(x, y, color, variety)
    
    -- board positions
    self.tier = 0
    self.gridX = x
    self.gridY = y
    self.isShiny = false

    self.psystem = love.graphics.newParticleSystem(gTextures['particle'], 10)

    self.psystem:setParticleLifetime(0.5, 1.0)

    self.psystem:setLinearAcceleration(-15, 55, 15, 100)

    -- spread of particles; normal looks more natural than uniform
    self.psystem:setEmissionArea('normal', 7, 6)

    -- coordinate positions
    self.x = (self.gridX - 1) * 32
    self.y = (self.gridY - 1) * 32

    -- tile appearance/points
    self.color = color
    self.variety = variety
end

function Tile:update(dt)
    self.psystem:emit(32)
    self.psystem:update(dt)
end

function Tile:render(x, y)
    
    -- draw shadow
    love.graphics.setColor(34, 32, 52, 255)
    love.graphics.draw(gTextures['main'], gFrames['tiles'][self.color][self.variety],
        self.x + x + 2, self.y + y + 2)

    -- draw tile itself
    love.graphics.setColor(255, 255, 255, 255)
    love.graphics.draw(gTextures['main'], gFrames['tiles'][self.color][self.variety],
        self.x + x, self.y + y)
end

function Tile:renderParticles(x, y)
    self.psystem:setColors(222, 222, 222, 255)
    self.psystem:emit(24)
    love.graphics.draw(self.psystem, self.x + x + 15, self.y + y + 10)
end