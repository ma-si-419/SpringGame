#include "DataManager.h"

void DataManager::LoadCsv()
{
    m_popLane.resize(99);

    std::string path = "data.csv";

    // �t�@�C���ǂݍ���
    std::wifstream ifs(path.c_str());
    if (!ifs)
    {
        assert(false);
        return;
    }

    std::wstring strBuf;
    std::vector<std::wstring> strConmaBuf;

    // �]���ȕ����̓ǂݍ���
    std::getline(ifs, strBuf);

    // �f�[�^���ׂēǂݍ���
    while (std::getline(ifs, strBuf))
    {
        strConmaBuf = Split(strBuf, ',');

        // �����[���擾
        int time = std::stoi(strConmaBuf[kTime]);

        std::wstring& leftLaneInfo = strConmaBuf[kLeftLane];
        auto& data = m_popLane[time];
        if (leftLaneInfo == L"0") {
            data.left = false;
        }
        else if (leftLaneInfo == L"1") {
            data.left = true;
        }

        // �E���[���擾
        std::wstring& rightLaneInfo = strConmaBuf[kRightLane];
        if (rightLaneInfo == L"0") {
            data.right = false;
        }
        else if (rightLaneInfo == L"1") {
            data.right = true;
        }
    }
}


std::vector<std::wstring> DataManager::Split(const std::wstring& str, const char del)
{
    // ��؂�J�n�ʒu
    int first = 0;
    // ��؂�ŏI�ʒu
    int last = static_cast<int>(str.find_first_of(del));

    std::vector<std::wstring> result;

    while (first < str.size())
    {
        // ��؂������̂����ʂɓ���Ă���
        std::wstring subStr(str, first, last - first);

        result.push_back(subStr);

        // �ʒu�X�V
        first = last + 1;
        last = static_cast<int>(str.find_first_of(del, first));
        if (last == std::wstring::npos)
        {
            last = static_cast<int>(str.size());
        }
    }

    return result;
}