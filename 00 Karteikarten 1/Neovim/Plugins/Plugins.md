normal: Cycle to the next buffer -> <C-;> -- :BufferLineCycleNext
normal: Cycle to the previous buffer -> <C-,> -- :BufferLineCyclePrev
normal: Close buffers to the left -> <leader>bc -- :BufferLineCloseLeft
normal: Close buffers to the right -> <leader>br -- :BufferLineCloseRight

normal: Toggle indent lines -> <leader>il -- :IndentBlanklineToggle

normal: Open project picker -> <leader>pp -- :Telescope projects
normal: Show project root -> <leader>pr -- :ProjectRoot

normal: Save session -> <leader>ss -- :SessionSave
normal: Load session -> <leader>sl -- :SessionLoad
normal: Close current session -> <leader>sc -- :SessionClose

normal: Open search and replace -> <leader>sr -- :Spectre
normal: Open Spectre with options -> <leader>sR -- :SpectreOpen

normal: Jump between syntax nodes -> <leader>th -- :lua require("tsht").nodes()
normal: Hop to parent node -> <leader>tp -- :lua require("tsht").parent()

normal: Open start screen -> <leader>st -- :Startify
normal: Save session from startify -> <leader>ss -- :SSave
normal: Load session from startify -> <leader>sl -- :SLoad

normal: Generate documentation -> <leader>nd -- :Neogen
normal: Generate documentation for function -> <leader>nF -- :Neogen func
normal: Generate documentation for class -> <leader>nC -- :Neogen class
normal: Generate documentation for type -> <leader>nT -- :Neogen type
normal: Generate documentation for file -> <leader>nG -- :Neogen file

normal: Show hover documentation -> <leader>lh -- :Lspsaga hover_doc
normal: Show code actions -> <leader>la -- :Lspsaga code_action
normal: Rename symbol -> <leader>lr -- :Lspsaga rename
normal: Jump to next diagnostic -> <leader>lj -- :Lspsaga diagnostic_jump_next
normal: Jump to previous diagnostic -> <leader>lk -- :Lspsaga diagnostic_jump_prev
normal: LSP finder -> <leader>lf -- :Lspsaga finder
normal: Show cursor diagnostics -> <leader>lc -- :Lspsaga show_cursor_diagnostics
normal: Jump to definition -> <leader>ld -- :Lspsaga goto_definition
normal: Jump to declaration -> <leader>lD -- :Lspsaga goto_declaration
normal: Show incoming calls -> <leader>li -- :Lspsaga incoming_calls
normal: Show outgoing calls -> <leader>lo -- :Lspsaga outgoing_calls
normal: Show symbol outline -> <leader>lO -- :Lspsaga lsp_finder
normal: Show hover documentation -> <leader>lh -- :Lspsaga hover_doc
normal: Show references -> <leader>lr -- :Lspsaga lsp_references
normal: Jump to type definition -> <leader>lt -- :Lspsaga goto_type_definition
