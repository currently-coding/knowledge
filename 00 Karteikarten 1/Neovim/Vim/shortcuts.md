n, x: Down -> j
n, x: Down ->\<Down>
n, x: Up -> k
<!--SR:!2024-08-15,3,269-->
n, x: Up ->\<Up>
n, t: Go to Left Window ->\<C-h>
n, t: Go to Lower Window ->\<C-j>
n, t: Go to Upper Window ->\<C-k>
n, t: Go to Right Window ->\<C-l>
n: Increase Window Height ->\<C-Up>
n: Decrease Window Height ->\<C-Down>
n: Decrease Window Width ->\<C-Left>
n: Increase Window Width ->\<C-Right>
n, i, v: Move Down ->\<A-j>
n, i, v: Move Up ->\<A-k>
n: Prev Buffer ->\<S-h>
n: Next Buffer ->\<S-l>
n: Prev Buffer -> [b
n: Next Buffer -> ]b
n: Switch to Other Buffer ->\<leader>bb
n: Switch to Other Buffer ->\<leader>`
n: Delete Buffer ->\<leader>bd
n: Delete Buffer and Window ->\<leader>bD
i, n: Escape and Clear hlsearch ->\<esc>
n: Redraw / Clear hlsearch / Diff Update ->\<leader>ur
n, x, o: Next Search Result -> n
<!--SR:!2024-08-15,3,268-->
n, x, o: Prev Search Result -> N
i, x, n, s: Save File ->\<C-s>
n: Keywordprg ->\<leader>K
n: Add Comment Below -> gco
n: Add Comment Above -> gcO
n: Lazy ->\<leader>l
n: New File ->\<leader>fn
n: Location List ->\<leader>xl
n: Quickfix List ->\<leader>xq
n: Previous Quickfix -> [q
n: Next Quickfix -> ]q
n, v: Format ->\<leader>cf
n: Line Diagnostics ->\<leader>cd
n: Next Diagnostic -> ]d
n: Prev Diagnostic -> [d
n: Next Error -> ]e
<!--SR:!2024-08-13,1,229-->
n: Prev Error -> [e
n: Next Warning -> ]w
n: Prev Warning -> [w
n: Toggle Auto Format (Global) ->\<leader>uf
<!--SR:!2024-08-13,1,229-->
n: Toggle Auto Format (Buffer) ->\<leader>uF
n: Toggle Spelling ->\<leader>us
n: Toggle Wrap ->\<leader>uw
n: Toggle Relative Number ->\<leader>uL
n: Toggle Diagnostics ->\<leader>ud
n: Toggle Line Numbers ->\<leader>ul
n: Toggle conceallevel ->\<leader>uc
n: Toggle Treesitter Highlight ->\<leader>uT
n: Toggle Background ->\<leader>ub
n: Toggle Inlay Hints ->\<leader>uh
n: Lazygit (Root Dir) ->\<leader>gg
n: Lazygit (cwd) ->\<leader>gG
n: Git Blame Line ->\<leader>gb
n: Git Browse ->\<leader>gB
n: Lazygit Current File History ->\<leader>gf
n: Lazygit Log ->\<leader>gl
n: Lazygit Log (cwd) ->\<leader>gL
n: Quit All ->\<leader>qq
n: Inspect Pos ->\<leader>ui
n: Inspect Tree ->\<leader>uI
n: LazyVim Changelog ->\<leader>L
n: Terminal (Root Dir) ->\<leader>ft
n: Terminal (cwd) ->\<leader>fT
<!--SR:!2024-08-13,1,228-->
n: Terminal (Root Dir) ->\<c-/>
n, t: which_key_ignore ->\<c-_>
t: Enter Normal Mode ->\<esc>|<esc>
t: Hide Terminal ->\<C-/>
n: Windows ->\<leader>w
n: Split Window Below ->\<leader>-
n: Split Window Right ->\<leader>|
n: Delete Window ->\<leader>wd
<!--SR:!2024-08-13,1,229-->
n: Toggle Maximize ->\<leader>wm
n: Last Tab ->\<leader>|<tab>l
n: Close Other Tabs ->\<leader>|<tab>o
n: First Tab ->\<leader>|<tab>f
n: New Tab ->\<leader>|<tab>|<tab>
n: Next Tab ->\<leader>|<tab>]
n: Close Tab ->\<leader>|<tab>d
n: Previous Tab ->\<leader>|<tab>[
n: Lsp Info ->\<leader>cl
n: Goto Definition -> gd
n: References -> gr
n: Goto Implementation -> gI
n: Goto T[y]pe Definition -> gy
n: Goto Declaration -> gD
n: Hover -> K
n: Signature Help -> gK
i: Signature Help ->\<c-k>
n, v: Code Action ->\<leader>ca
n, v: Run Codelens ->\<leader>cc
n: Refresh & Display Codelens ->\<leader>cC
<!--SR:!2024-08-13,1,229-->
n: Rename File ->\<leader>cR
<!--SR:!2024-08-15,3,268-->
n: Rename ->\<leader>cr
n: Source Action ->\<leader>cA
n: Next Reference -> ]]
n: Prev Reference -> [[
<!--SR:!2024-08-13,1,228-->
n: Next Reference ->\<a-n>
n: Prev Reference ->\<a-p>
n: Delete Buffers to the Left ->\<leader>bl
n: Delete Other Buffers ->\<leader>bo
n: Toggle Pin ->\<leader>bp
n: Delete Non-Pinned Buffers ->\<leader>bP
n: Delete Buffers to the Right ->\<leader>br
n: Prev Buffer -> [b
n: Move buffer prev -> [B
n: Next Buffer -> ]b
n: Move buffer next -> ]B
n: Prev Buffer ->\<S-h>
n: Next Buffer ->\<S-l>
n, v: Format Injected Langs ->\<leader>cF
c: Toggle Flash Search ->\<c-s>
o: Remote Flash -> r
o, x: Treesitter Search -> R
n, o, x: Flash -> s
n, o, x: Flash Treesitter -> S
n, v: Search and Replace ->\<leader>sr
n: Mason ->\<leader>cm
n: Buffer Explorer ->\<leader>be
n: Explorer NeoTree (Root Dir) ->\<leader>e
<!--SR:!2024-08-14,2,248-->
n: Explorer NeoTree (cwd) ->\<leader>E
n: Explorer NeoTree (Root Dir) ->\<leader>fe
<!--SR:!2024-08-15,3,269-->
n: Explorer NeoTree (cwd) ->\<leader>fE
n: Git Explorer ->\<leader>ge
n, i, s: Scroll Backward ->\<c-b>
n, i, s: Scroll Forward ->\<c-f>
n: +noice ->\<leader>sn
n: Noice All ->\<leader>sna
n: Dismiss All ->\<leader>snd
n: Noice History ->\<leader>snh
n: Noice Last Message ->\<leader>snl
n: Noice Picker (Telescope/FzfLua) ->\<leader>snt
c: Redirect Cmdline ->\<S-Enter>
n: Dismiss All Notifications ->\<leader>un
x: Decrement Selection ->\<bs>
n: Increment Selection ->\<c-space>
n: Don't Save Current Session ->\<leader>qd
n: Restore Last Session ->\<leader>ql
n: Restore Session ->\<leader>qs
n: Find Files (Root Dir) ->\<leader>|<space>
n: Switch Buffer ->\<leader>,
n: Grep (Root Dir) ->\<leader>/
n: Command History ->\<leader>:
n: Buffers ->\<leader>fb
n: Find Config File ->\<leader>fc
<!--SR:!2024-08-15,3,269-->
n: Find Files (Root Dir) ->\<leader>ff
n: Find Files (cwd) ->\<leader>fF
n: Find Files (git-files) ->\<leader>fg
n: Recent ->\<leader>fr
n: Recent (cwd) ->\<leader>fR
n: Commits ->\<leader>gc
n: Status ->\<leader>gs
n: Registers ->\<leader>s"
n: Auto Commands ->\<leader>sa
n: Buffer ->\<leader>sb
n: Command History ->\<leader>sc
n: Commands ->\<leader>sC
<!--SR:!2024-08-13,1,228-->
n: Document Diagnostics ->\<leader>sd
n: Workspace Diagnostics ->\<leader>sD
|<!--SR:!2024-08-13,1,230-->
n: Grep (Root Dir) ->\<leader>sg
n: Grep (cwd) ->\<leader>sG
n: Help Pages ->\<leader>sh
n: Search Highlight Groups ->\<leader>sH
n: Jumplist ->\<leader>sj
n: Key Maps ->\<leader>sk
n: Location List ->\<leader>sl
n: Jump to Mark ->\<leader>sm
n: Man Pages ->\<leader>sM
n: Options ->\<leader>so
n: Quickfix List ->\<leader>sq
n: Resume ->\<leader>sR
n: Goto Symbol ->\<leader>ss
n: Goto Symbol (Workspace) ->\<leader>sS
n: Word (Root Dir) ->\<leader>sw
n: Word (cwd) ->\<leader>sW
v: Selection (Root Dir) ->\<leader>sw
v: Selection (cwd) ->\<leader>sW
n: Colorscheme with Preview ->\<leader>uC
n: Todo ->\<leader>st
n: Todo/Fix/Fixme ->\<leader>sT
n: Todo (Trouble) ->\<leader>xt
n: Todo/Fix/Fixme (Trouble) ->\<leader>xT
n: Previous Todo Comment -> [t
n: Next Todo Comment -> ]t
n: Symbols (Trouble) ->\<leader>cs
n: LSP references/definitions/... (Trouble) ->\<leader>cS
n: Location List (Trouble) ->\<leader>xL
n: Quickfix List (Trouble) ->\<leader>xQ
n: Diagnostics (Trouble) ->\<leader>xx
n: Buffer Diagnostics (Trouble) ->\<leader>xX
n: Previous Trouble/Quickfix Item -> [q
<!--SR:!2024-08-13,1,228-->
n: Next Trouble/Quickfix Item -> ]q
n: Window Hydra Mode (which-key) ->\<c-w>|<space>
n: Buffer Keymaps (which-key) ->\<leader>?
