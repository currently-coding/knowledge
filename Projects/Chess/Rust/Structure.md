### Board
- pieces: `[u64; 12]` store all the piece positions
- sides: `[u64; 2]` store all the pieces from each side

### GameState
- en_passant: `u64` // the position en-passant is currently possible
- castling: `u8`  // each bit signals one direction one may castle
- active_color: `[Color]`
- board: `Board`

### History
- history: `[GameState; u64]`
- move_number: `u64`


## Behaviour
### Undo_Move
- revert to `History.history[History.move_number-1]`


### Generate_Moves