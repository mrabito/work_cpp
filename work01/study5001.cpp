/*
 *  2017/07/27
 *  Boostを使ったファイル入出力のテスト(.xml)
 *	参照サイト: http://e-kwsm.hatenablog.com/entry/2015/05/20/053502
 */

#include <string>
#include <locale>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

int main()
{
	// 空のプロパティツリーを作る
	boost::property_tree::ptree pt;

	// ルート要素(ルートノードではない)を作る
	boost::property_tree::ptree& root = pt.put("messages", "");

	// 要素ノードを追加する
	// 絶対パス
	pt.put("messages.note.<xmlattr>.id", "501");	// <xmlattr>で属性を追加
	pt.put("messages.note.to", "Tove");
	pt.put("messages.note.from", "Jani");
	pt.put("messages.note.heading", "Reminder");
	pt.put("messages.note.body", "Don't forget me this weekend!");
	// 相対パス
	boost::property_tree::ptree& child = root.add("note", "");
	child.put("<xmlattr>.id", "502");
	child.put("to", "Jani");
	child.put("from", "Tove");
	child.put("heading", "Re: Reminder");
	child.put("body", "I will not");

	// ファイル出力
	boost::property_tree::write_xml("_data/data5001.xml", pt, std::locale(),
		boost::property_tree::xml_writer_make_settings<std::string>(' ', 2));

	return 0;
}