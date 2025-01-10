--[[
    PauseState Class
    
    Author: Ryan Smith
    rysmith25@hotmail.com

    The PauseState pauses the game
]]

PauseState = Class{__includes = BaseState}

function PauseState:init()
    -- nothing
end

function PauseState:update(dt)
    if love.keyboard.wasPressed('space') then
        gStateMachine:change('play')
    end
end

function PauseState:render()
    love.graphics.setFont(mediumFont)
    love.graphics.printf('Paused', 0, 100, VIRTUAL_WIDTH, 'center')
end