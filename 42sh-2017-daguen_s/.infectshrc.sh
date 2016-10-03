#!infect

alias +='pushd\ .'
alias -='popd'
alias ..='cd\ ..'
alias ...='cd\ ../..'
alias beep='echo\ -en\ \\\\007'
alias cd..='cd\ ..'
alias dir='ls\ -l'
alias egrep='egrep\ --color=auto'
alias emacs='emacs\ -nw'
alias fgrep='fgrep\ --color=auto'
alias grep='grep\ --color=auto'
alias j='jobs'
alias l='ls\ -alF'
alias la='ls\ -la'
alias ll='ls\ -l'
alias ls="ls\ --color=auto"
alias md='mkdir\ -p'
alias ne='emacs'
alias o='less'
alias rd='rmdir'
alias rehash='hash\ -r'
PROMPT=3
if [ $1 = "-p" ]
    echo which prompt do you want
    echo 1) time
    echo 2) pwd
    read PROMPT
    fi
case $PROMPT in
    0) setenv PS1 '$USER\>'
    1) setenv PS1 'Segmentation\ fault"  "'
    3) setenv PS1 '(%yellow$USER%&@%green$HOSTNAME%&\ %com\ %t)'
    2) setenv PS1 '(%yellow$USER%&@%green$HOSTNAME%&$PWD)'
esac

if [ -f ${HOME}/.myinfectshrc ]; then
    ${HOME}/.myinfectshrc
    fi
