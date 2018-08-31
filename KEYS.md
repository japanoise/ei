# The Immortal Keybindings

ei uses a novel keybinding system designed to minimise unnecessary travel. This
is why separate versions are provided for Dvorak and Qwerty. If there's demand,
I'll also design versions for Colemak and Workman.

To activate a command, you must press a modifier key and then the corresponding
character on the keyboard. All keybindings work with either Control or Alt
(Meta on very old keyboards).  They have been chosen to keep the most important
keys (movement) on the home row, and keys that you don't want to be mashing
(kill word, replace) out of the way.

If your terminal sends e.g. C-H for backspace, C-J for newlines, C-I for tabs,
you'd be strongly advised to use Alt instead of Control for these bindings, to
prevent them from clashing.

Most of the keys occupy the same spaces on the keyboard in dvorak and qwerty:

```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│Q"   │W<   │E>   │RP   │TY   │YF   │UG   │IC   │OR   │PL   │
│     │     │     │Load │BOL  │EOL  │Undo │←kwrd│kwrd→│Rplce│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│AA   │SO   │DE   │FU   │GI   │HD   │JH   │KT   │LN   │;S   │
│←word│word→│←char│char→│Snarf│Kill │↓line│line↑│↓para│para↑│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│Z:   │XQ   │CJ   │VK   │BX   │NB   │MM   │<W   │>V   │?Z   │
│     │Exit │Save │Spew │CMD  │K-BOL│K-EOL│     │     │     │
├─────┼─────┼─────┼─────┴─────┴─────┼─────┼─────┼─────┼─────┤
│CTRL │META │ALT  │SPACE BAR        │ALT  │META │MENU │CTRL │
│     │     │     │Set mark         │     │     │     │     │
└─────┴─────┴─────┴─────────────────┴─────┴─────┴─────┴─────┘
```

The only major exceptions right now are page up and page down:

- On dvorak, Mod-Z and Mod-V (mirroring emacsen)
- On qwerty, Mod-W and Mod-E

Word and paragraph have been defined as simply as possible for now (a word is a
group of non-space characters; a paragraph is a group of non-empty lines).
