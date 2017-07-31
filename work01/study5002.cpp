/*
 *  2017/07/28
 *  BoostのXMLパーサ / 読込
 *	参照サイト: https://boostjp.github.io/tips/xml.html
 */

#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>

int main()
{
	using namespace boost::property_tree;

	ptree pt;
	read_xml("_data/data5002.xml", pt);

	if (boost::optional<std::string> str = pt.get_optional<std::string>("root.str")) {
		std::cout << str.get() << std::endl;
	}
	else {
		std::cout << "root.str がないよ" << std::endl;
	}

	BOOST_FOREACH(const ptree::value_type& child, pt.get_child("root.values")) {
		const int value = boost::lexical_cast<int>(child.second.data());
		std::cout << value << std::endl;
	}
	getchar();
}