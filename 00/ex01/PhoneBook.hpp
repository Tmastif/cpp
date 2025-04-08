/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:37:27 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/08 14:15:48 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


class PhoneBook
{
	static const int MAX_CONTACTS = 8;
	int contactCount;
	int counter;
	Contact contacts[MAX_CONTACTS];

  public:
	PhoneBook() : contactCount(0), counter(0){};

	void addcontact(Contact newContact)
	{
		if (counter == MAX_CONTACTS)
			counter = 0;
		if (contactCount < MAX_CONTACTS)
			contactCount++;
		contacts[counter] = newContact;
		counter++;
	}

	std::string truncStr(std::string str)
	{
		if (str.length() > 10)
			return (str.substr(0, 9) + ".");
		return (std::string(10 - str.length(), ' ') + str);
	}

	void displayContacts()
	{
		std::cout << std::setw(10) << "index"
					<< "|" << std::setw(10) << "first name"
					<< "|" << std::setw(10) << "last name"
					<< "|" << std::setw(10) << "nickname"
					<< "\n";

		for (int i = 0; i < contactCount; i++)
		{
			std::cout << std::setw(10) << i << "|"
			<< std::setw(10) << truncStr(contacts[i].getFirstname()) << "|"
			<< std::setw(10) << truncStr(contacts[i].getLastname()) << "|"
			<< std::setw(10) << truncStr(contacts[i].getNickname()) << std::endl;
		}
	}

	static int getId()
	{
		std::string input;

		int id = -1;
		while (1)
		{
			std::cout << "Enter contact's id:\n";
			std::cin >> input;
			if (input.length() == 1 && std::isdigit(input[0]))
			{
				id = input[0] - '0';
				break ;
			}
		}
		return (id);
	}

	void displayFullContact()
	{
		int id;

		if (contactCount == 0)
			std::cout << "The phonebook is still empty.\n";
		else
		{
			while (1)
			{
				id = getId();
				if (id < contactCount && id >= 0)
					break ;
				std::cout << "Chosen id is out of range.\n";
			}
			std::cout << contacts[id].getFirstname() << std::endl;
			std::cout << contacts[id].getLastname() << std::endl;
			std::cout << contacts[id].getNickname() << std::endl;
			std::cout << contacts[id].getSecret() << std::endl;
			std::cout << contacts[id].getPhone() << std::endl;
		}
	}
};

#endif
