--[[
    GD50
    Legend of Zelda

    Author: Colton Ogden
    cogden@cs50.harvard.edu
]]

GAME_OBJECT_DEFS = {
    ['switch'] = {
        type = 'switch',
        texture = 'switches',
        frame = 2,
        width = 16,
        height = 16,
        solid = false,
        defaultState = 'unpressed',
        states = {
            ['unpressed'] = {
                frame = 2
            },
            ['pressed'] = {
                frame = 1
            }
        }
    },

    ['hearts'] = {
        type = 'hearts',
        texture = 'hearts',
        frame = 5,
        width = 16,
        height = 16,
        solid = false,
        defaultState = 'on',
        states = {
            ['on'] = {
                frame = 5
            },
            ['off'] = {
                frame = 1
            }
        }
    },
    
    ['pot'] = {
        type = 'pot',
        texture = 'tiles',
        frame = 14,
        width = 16,
        height = 16,
        solid = true,
        defaultState = 'on',
        states = {
            ['on'] = {
                frame = 14
            },
            ['off'] = {
                frame = 52
            }
        }
    }
}