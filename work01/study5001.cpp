/*
 *  2017/07/27
 *  Boost���g�����t�@�C�����o�͂̃e�X�g(.xml)
 *	�Q�ƃT�C�g: http://e-kwsm.hatenablog.com/entry/2015/05/20/053502
 */

#include <string>
#include <locale>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

int main()
{
	// ��̃v���p�e�B�c���[�����
	boost::property_tree::ptree pt;

	// ���[�g�v�f(���[�g�m�[�h�ł͂Ȃ�)�����
	boost::property_tree::ptree& root = pt.put("messages", "");

	// �v�f�m�[�h��ǉ�����
	// ��΃p�X
	pt.put("messages.note.<xmlattr>.id", "501");	// <xmlattr>�ő�����ǉ�
	pt.put("messages.note.to", "Tove");
	pt.put("messages.note.from", "Jani");
	pt.put("messages.note.heading", "Reminder");
	pt.put("messages.note.body", "Don't forget me this weekend!");
	// ���΃p�X
	boost::property_tree::ptree& child = root.add("note", "");
	child.put("<xmlattr>.id", "502");
	child.put("to", "Jani");
	child.put("from", "Tove");
	child.put("heading", "Re: Reminder");
	child.put("body", "I will not");

	// �t�@�C���o��
	boost::property_tree::write_xml("_data/data5001.xml", pt, std::locale(),
		boost::property_tree::xml_writer_make_settings<std::string>(' ', 2));

	return 0;
}