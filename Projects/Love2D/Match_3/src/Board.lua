--[[
    GD50
    Match-3 Remake

    -- Board Class --

    Author: Colton Ogden
    cogden@cs50.harvard.edu

    The Board is our arrangement of Tiles with which we must try to find matching
    sets of three horizontally or vertically.
]]

Board = Class{} -- line 455

local level = 1

function Board:init(x, y, level)
    self.x = x
    self.y = y
    self.matches = {}
    self.bIsShiny = false
    self.bonusMatches = 0
    self.removedTiles = 0
    self.currentLevel = level
    self:initializeTiles()
end

function Board:initializeTiles()
    self.tiles = {}    

    for tileY = 1, 8 do
        
        -- empty table that will serve as a new row
        table.insert(self.tiles, {})

        for tileX = 1, 8 do
            
            -- create a new tile at X,Y with a random color and variety
            table.insert(self.tiles[tileY], Tile(tileX, tileY, math.random(5), math.random(self.currentLevel)))
        end
    end

    while self:calculateMatches() do
        
        -- recursively initialize if matches were returned so we always have
        -- a matchless board on start
        self:initializeTiles()
    end
end

--[[
    Goes left to right, top to bottom in the board, calculating matches by counting consecutive
    tiles of the same color. Doesn't need to check the last tile in every row or column if the 
    last two haven't been a match.
]]

function Board:calculateMatches()
    local matches = {}
    local bonus = 0
    local varietyToMatch = 0

    -- how many of the same color blocks in a row we've found
    local matchNum = 1
    local shinyMatches = 0;
    --

    -- VARIETY
    if self.currentLevel > 1 then
        -- HORIZONTAL
        for y = 1, 8 do

            varietyToMatch = self.tiles[y][1].variety

            matchNum = 1
            
            -- every horizontal tile
            for x = 2, 8 do              
                
                -- if this is the same color as the one we're trying to match...
                if self.tiles[y][x].variety == varietytoMatch and varietytoMatch > 1 then
                    matchNum = matchNum + 1
                else
                    
                    -- set this as the new color we want to watch for
                    varietytoMatch = self.tiles[y][x].variety

                    -- if we have a match of 3 or more up to now, add it to our matches table
                    if matchNum >= 3 then
                        local match = {}

                        -- go backwards from here by matchNum
                        for x2 = x - 1, x - matchNum, -1 do
                            
                            -- add each tile to the match that's in that match
                            table.insert(match, self.tiles[y][x2])
                        end

                        -- add this match to our total matches table                        
                        table.insert(matches, match)
                        if bonus == 0 then
                            bonus = 1
                        else
                            bonus = bonus + bonus * varietyToMatch
                        end
                    end

                    matchNum = 1

                end
            end

            -- account for the last row ending with a match
            if matchNum >= 3 then
                local match = {}
                
                -- go backwards from end of last row by matchNum
                for x = 8, 8 - matchNum + 1, -1 do
                    table.insert(match, self.tiles[y][x])
                end

                table.insert(matches, match)
            end
        end

        -- VARIETY | VERTICAL
        for x = 1, 8 do

            varietyToMatch = self.tiles[1][x].variety

            matchNum = 1

            -- every vertical tile
            for y = 2, 8 do
                if self.tiles[y][x].variety == varietytoMatch and varietytoMatch > 1 then
                    matchNum = matchNum + 1
                else
                    varietytoMatch = self.tiles[y][x].variety

                    if matchNum >= 3 then
                        local match = {}

                        for y2 = y - 1, y - matchNum, -1 do
                            table.insert(match, self.tiles[y2][x])
                        end
                        
                        if bonus == 0 then
                            bonus = 1
                        else
                            bonus = bonus + bonus * varietyToMatch
                        end

                        table.insert(matches, match)
                    end

                    matchNum = 1

                end
            end

            -- account for the last column ending with a match
            if matchNum >= 3 then
                local match = {}
                
                -- go backwards from end of last row by matchNum
                for y = 8, 8 - matchNum + 1, -1 do
                    table.insert(match, self.tiles[y][x])
                end

                table.insert(matches, match)
            end
        end
    end

    -- HORIZONTAL | COLORS
    for y = 1, 8 do
        local colorToMatch = self.tiles[y][1].color

        matchNum = 1

        self.bIsShiny = self.tiles[y][1].isShiny
        if self.bIsShiny == true then
            shinyMatches = 1
        end

        local match = {}
        
        -- every horizontal tile
        for x = 2, 8 do        
            
            -- if this is the same color as the one we're trying to match...            
            if matchNum >= 3 and shinyMatches >= 3 then

                shinyMatches = 1
                self.bIsShiny = false
                colorToMatch = self.tiles[y][x].color
                match = {}
                matchNum = 8
                    -- go backwards from end of last row by matchNum
                    for x3 = 8, 8 - matchNum + 1, -1 do
                        table.insert(match, self.tiles[y][x3])
                    end
                table.insert(matches, match)
                matchNum = 1
            
            elseif self.tiles[y][x].color == colorToMatch and self.tiles[y][x].isShiny == true then
                matchNum = matchNum + 1
                shinyMatches = shinyMatches + 1
            elseif self.tiles[y][x].color == colorToMatch then
                matchNum = matchNum + 1
            else                
                -- set this as the new color we want to watch for
                colorToMatch = self.tiles[y][x].color
                -- if we have a match of 3 or more up to now, add it to our matches table
                if matchNum >= 3 then
                    match = {}                    
                    -- go backwards from here by matchNum
                    for x2 = x - 1, x - matchNum, -1 do                        
                        -- add each tile to the match that's in that match
                        table.insert(match, self.tiles[y][x2])
                    end              

                    -- add this match to our total matches table
                    table.insert(matches, match)
                end

                matchNum = 1

            end
        end

        -- account for the last row ending with a match
        if matchNum >= 3 then
            local match = {}
            
            -- go backwards from end of last row by matchNum
            for x = 8, 8 - matchNum + 1, -1 do
                table.insert(match, self.tiles[y][x])
            end

            table.insert(matches, match)
        end
    end

    -- VERTICAL | COLORS
    for x = 1, 8 do
        local colorToMatch = self.tiles[1][x].color

        matchNum = 1

        -- every vertical tile
        for y = 2, 8 do
            if self.tiles[y][x].color == colorToMatch then
                matchNum = matchNum + 1
            else
                colorToMatch = self.tiles[y][x].color

                if matchNum >= 3 then
                    local match = {}

                    for y2 = y - 1, y - matchNum, -1 do
                        table.insert(match, self.tiles[y2][x])
                    end

                    table.insert(matches, match)
                end

                matchNum = 1

                -- don't need to check last two if they won't be in a match
                if y >= 7 then
                    break
                end
            end
        end

        -- account for the last column ending with a match
        if matchNum >= 3 then
            local match = {}
            
            -- go backwards from end of last row by matchNum
            for y = 8, 8 - matchNum + 1, -1 do
                table.insert(match, self.tiles[y][x])
            end

            table.insert(matches, match)
        end
    end

    -- store matches for later reference
    self.matches = matches
    self.bonusMatches = bonus
    bonus = 0

    -- return matches table if > 0, else just return false
    return #self.matches > 0 and self.matches or false
end

function Board:removeMatches()
    self.removedTiles = 0

    for k, match in pairs(self.matches) do
        for k, tile in pairs(match) do
            self.tiles[tile.gridY][tile.gridX] = nil
            self.removedTiles = self.removedTiles + 1
        end
    end

    self.matches = nil
end

--[[
    Shifts down all of the tiles that now have spaces below them, then returns a table that
    contains tweening information for these new tiles.
]]
function Board:getFallingTiles()
    -- tween table, with tiles as keys and their x and y as the to values
    local tweens = {}

    self.newTiles = 0

    -- for each column, go up tile by tile till we hit a space
    for x = 1, 8 do
        local space = false
        local spaceY = 0

        local y = 8
        while y >= 1 do
            
            -- if our last tile was a space...
            local tile = self.tiles[y][x]
            
            if space then
                
                -- if the current tile is *not* a space, bring this down to the lowest space
                if tile then
                    
                    -- put the tile in the correct spot in the board and fix its grid positions
                    self.tiles[spaceY][x] = tile
                    tile.gridY = spaceY

                    -- set its prior position to nil
                    self.tiles[y][x] = nil

                    -- tween the Y position to 32 x its grid position
                    tweens[tile] = {
                        y = (tile.gridY - 1) * 32
                    }

                    -- set Y to spaceY so we start back from here again
                    space = false
                    y = spaceY

                    -- set this back to 0 so we know we don't have an active space
                    spaceY = 0
                end
            elseif tile == nil then
                space = true
                
                -- if we haven't assigned a space yet, set this to it
                if spaceY == 0 then
                    spaceY = y
                end
            end

            y = y - 1
        end
    end

    -- create replacement tiles at the top of the screen
    for x = 1, 8 do
        for y = 8, 1, -1 do
            local tile = self.tiles[y][x]

            -- if the tile is nil, we need to add a new one
            if not tile then

                -- new tile with random color and variety
                local tile = Tile(x, y, math.random(2), math.random(self.currentLevel))
                tile.y = -32

                shinNum = math.random(2)
                if shinNum == 1 then
                    tile.isShiny = true
                else
                    tile.isShiny = false
                end

                self.tiles[y][x] = tile

                -- create a new tween to return for this tile to fall down
                tweens[tile] = {
                    y = (tile.gridY - 1) * 32
                }
            end
        end
    end

    return tweens
end

function Board:swapTiles(tile1, tile2)

    local tempX = tile1.gridX
    local tempY = tile1.gridY
    
    tile1.gridX = tile2.gridX
    tile1.gridY = tile2.gridY
    tile2.gridX = tempX
    tile2.gridY = tempY

    self.tiles[tile1.gridY][tile1.gridX] = tile1
    self.tiles[tile2.gridY][tile2.gridX] = tile2
end

function Board:anyMatches()

    for y = 1, 8 do
        for x = 1, 8 do

            if x > 1 then
                self:swapTiles(self.tiles[y][x], self.tiles[y][x - 1])
                if self:calculateMatches() then
                    self:swapTiles(self.tiles[y][x], self.tiles[y][x-1])
                    return true
                end
                self:swapTiles(self.tiles[y][x], self.tiles[y][x - 1])
            end

            if y > 1 then
                self:swapTiles(self.tiles[y][x], self.tiles[y-1][x])
                if self:calculateMatches() then
                    self:swapTiles(self.tiles[y][x], self.tiles[y-1][x])
                    return true
                end
                self:swapTiles(self.tiles[y][x], self.tiles[y-1][x])
            end

            if x <= 7 then
                self:swapTiles(self.tiles[y][x], self.tiles[y][x + 1])
                if self:calculateMatches() then
                    self:swapTiles(self.tiles[y][x], self.tiles[y][x + 1])
                    return true
                end
                self:swapTiles(self.tiles[y][x], self.tiles[y][x + 1])
            end
            
            if y <= 7 then
                self:swapTiles(self.tiles[y][x], self.tiles[y + 1][x])
                if self:calculateMatches() then
                    self:swapTiles(self.tiles[y][x], self.tiles[y + 1][x])
                    return true
                end
                self:swapTiles(self.tiles[y][x], self.tiles[y + 1][x])
            end
        end
    end

    return false

end


function Board:render()
    for y = 1, #self.tiles do
        for x = 1, #self.tiles[1] do           
            if self.tiles[y][x].isShiny == true then                
                self.tiles[y][x]:render(self.x, self.y)
                self.tiles[y][x]:renderParticles(self.x, self.y)                
            else
                self.tiles[y][x]:render(self.x, self.y)
            end
        end
    end
end