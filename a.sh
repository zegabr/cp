# a for aliases
# add aliases for bash terminal

git clone https://github.com/zegabr/pyutils

FILE=~/.oh-my-zsh/oh-my-zsh.sh

if [ -f "$FILE" ]; then
    python3 pyutils/replace_content_in_tag.py ~/.oh-my-zsh/oh-my-zsh.sh ./stuff/aliases.sh "##COMPETITIVE"
    echo "============you have new aliases for zsh==========="
    source ~/.oh-my-zsh/oh-my-zsh.sh
else 
    echo "$FILE does not exist."
    python3 pyutils/replace_content_in_tag.py ~/.bashrc ./stuff/aliases.sh "##COMPETITIVE"
    echo "============you have new aliases for bash==========="
    source ~/.bashrc
fi

echo "removing pyutils"
rm -rf pyutils