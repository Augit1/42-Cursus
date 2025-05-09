# include "Channel.hpp"

Channel::Channel()
	: _name(""), _topic(":No topic is set"), _members(), _operators(), _invited(), _modes(), _userLimit(-1) {}

Channel::Channel(const std::string& name)
	: _name(name), _topic(":No topic is set"), _members(), _operators(), _invited(), _modes(), _userLimit(-1) {}

Channel::Channel(const Channel& other)
	: _name(other._name),
	  _topic(other._topic),
	  _members(other._members),
	  _operators(other._operators),
	  _invited(other._invited),
	  _modes(other._modes),
	  _userLimit(other._userLimit) {}

Channel&	Channel::operator=(const Channel& other)
{
	if (this != &other)
	{
		_name = other._name;
		_topic = other._topic;
		_members = other._members;
		_operators = other._operators;
		_invited = other._invited;
		_modes = other._modes;
		_userLimit = other._userLimit;
	}
	return *this;
}

Channel::~Channel() {}

bool				Channel::isMember  				(int fd)
{
	if (_members.empty())
		return (false);
	for (std::map<int, Client*>::const_iterator it = _members.begin(); it != _members.end(); it++)
	{
		if ((it->second)->getSocket() == fd)
			return (true);
	}
	return(false); 	
}
bool				Channel::isOperator				(int fd)                      	const
{
	if (_operators.find(fd) != _operators.end())
		return (true);
	return (false);
}
bool				Channel::isInvited 				(int fd)                      	const
{
	if (_invited.find(fd) == _invited.end())
		return (false);
	return	(true);
}
	
void				Channel::makeOperator			(Server& server, int fd)
{
	Client* client = server.getClient(fd);
	_operators[fd] = client;
}
void	 			Channel::invite					(Server& server, int fd)
{
	Client* client = server.getClient(fd);
	_invited[fd] = client;
}
void				Channel::makeMember				(Server& server, int fd)
{
	Client* client = server.getClient(fd);
	
	_members[fd] = client;
	if (this->_members.size() == 1)
		this->makeOperator(server, client->getSocket());
}
	
void				Channel::removeMember			(int fd)
{
	_members.erase(fd);
}
void				Channel::uninvite				(int fd)
{
	_invited.erase(fd);
}
void				Channel::removeOperator			(int fd)
{
	_operators.erase(fd);
}
	
void 				Channel::deleteMember			(int fd)
{
	if (isMember  (fd))	removeMember  (fd);
	if (isInvited (fd))	uninvite      (fd);
	if (isOperator(fd))	removeOperator(fd);
}
	
const std::string&	Channel::getTopic				() 								const
{
	return (_topic);
}
void 				Channel::setTopic				(const std::string& topic)
{
	_topic = topic;
}
	
void				Channel::setPassword			(const std::string& password)
{
	_password = password;
}
bool				Channel::checkPassword			(const std::string& password) 	const
{
	return _password == password;
}
	
bool				Channel::hasMode				(char mode) 					const
{
	return _modes.find(mode) != _modes.end();
}
void				Channel::setMode   				(char mode, bool enable)
{
	if (enable)
		_modes.insert(mode);
	else
		_modes.erase(mode);
}

std::string			Channel::getModes() const
{
	std::string message = "";

	if (this->hasMode(INVITE_ONLY)) 		message += INVITE_ONLY;
	if (this->hasMode(TOPIC_PROTECTED)) 	message += TOPIC_PROTECTED;
	if (this->hasMode(KEY_WORD)) 			message += KEY_WORD;
	if (this->hasMode(SIZE_LIMIT))			message += SIZE_LIMIT;

	return (message);
}
	
void				Channel::setUsersLimit			(int limit)
{
	_userLimit = limit;
}
	
int					Channel::getUsersLimit() 			const
{
	return _userLimit;
}

Client* Channel::getMember(std::string username)
{
	for (std::map<int, Client*>::const_iterator it = _members.begin(); it != _members.end(); it++)
		if ((it->second)->getNickname() == username)
			return (it->second);
	return(NULL); 	
}

std::string Channel::getName()
{
    return (this->_name);
}

void				Channel::copyMemberToInvite		()
{
	_invited = _members;
}

void				Channel::deleteInviteElements	()
{
	for (std::map<int, Client*>::iterator it = _invited.begin(); it != _invited.end(); it++)
		_invited.erase(it->first);
}

void Channel::broadcastMessage(const std::string& message, int senderFd)
{
    if (!_members.size()) {
        std::cerr << "Channel members list is empty: " << getName() << std::endl;
        return;
    }

    if (message.empty()) {
        std::cerr << "Message is empty, nothing to broadcast." << std::endl;
        return;
    } 
    for (std::map<int, Client*>::iterator it = _members.begin();
        it != _members.end(); it++)
    {
        if (!it->second) {
            std::cerr << "Invalid client pointer for FD: " << it->first << std::endl;
            continue;
        }
        int fd = it->first;
		if (fd != senderFd)
		{
			if (send(fd, message.c_str(), message.length(), 0) == -1)
				std::cerr << "Error broadcasting to FD: " << fd << " - " << std::endl;
		}
	}
}

int Channel::userCount()  const
{
	return (_members.size());
}

std::map<int, Client*>*		Channel::getMembers()
{
	return &_members;
}
