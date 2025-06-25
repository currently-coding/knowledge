```bash
bindkey '^R' fzf-history-widget
fzf-history-widget() {
  local selected=$(history | fzf --tac +s --no-sort --reverse --height 40% --border --prompt="History > " | sed 's/^[ 0-9]*//')
  LBUFFER+="$selected"
  zle redisplay
}
zle -N fzf-history-widget

finder() {
  local selected
  selected=$(find . -type f 2> /dev/null | sed 's|^\./||' | fzf --tac +s --no-sort --reverse --height 40% --border --prompt="File > ")
  if [[ -n $selected ]]; then
    LBUFFER+="$EDITOR \"$selected\""
  fi
  zle redisplay
}
zle -N finder
bindkey '^F' finder  # bind to Ctrl+F

```