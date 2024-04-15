#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

namespace
{
    const char* const kOutPath = "FileManager.bin";

    enum Index : int
    {
        kName,
        kType,
        kPath,
        kExtension
    };

    enum class LoadType
    {
        kImage,
        kSound,
        kModel
    };
    struct Path
    {
        LoadType type = LoadType::kImage;
        std::wstring path = L"";
    };

    constexpr float kVar = 1.0f;
    struct Header
    {
        float var = kVar;
        int size = 0;
    };
}


// �p�X�f�[�^
using PathData_t = std::unordered_map<std::wstring, Path>;

void LoadCsv(PathData_t& data);
void WriteBin(PathData_t& data);
std::vector<std::wstring> Split(const std::wstring& str, const char del);

int main()
{
    PathData_t datas;
    LoadCsv(datas);
    WriteBin(datas);

    datas[L"Player"].path;

    LoadGraph(L"Data/Image/test.png");
    LoadGraph(datas[L"Player"].path.c_str());

	return 0;
}

void LoadCsv(PathData_t& datas)
{
    std::string path;
    std::cin >> path;

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

        // ���O�擾
        std::wstring& name = strConmaBuf[kName];

        // ��ގ擾
        std::wstring& typeName = strConmaBuf[kType];
        LoadType type = LoadType::kImage;
        if (typeName == L"Image") {
            type = LoadType::kImage;
        }
        else if (typeName == L"Sound") {
            type = LoadType::kSound;
        }
        else if (typeName == L"Model") {
            type = LoadType::kModel;
        }

        // �p�X�擾
        std::wostringstream path;
        path << L"Data/";
        if (type == LoadType::kImage) {
            path << L"Image/";
        }
        else if (type == LoadType::kSound) {
            path << L"Sound/";
        }
        else if (type == LoadType::kModel) {
            path << L"Model/";
        }
        path << strConmaBuf[kPath] << L"." << strConmaBuf[kExtension];

        auto& data = datas[name];
        data.type = type;
        data.path = path.str();
    }
}

void WriteBin(PathData_t& datas)
{
    FILE* fp;

    // �t�@�C���ǂݍ���
    auto err = fopen_s(&fp, kOutPath, "wb");
    if (err != 0)
    {
        assert(false);
        return;
    }

    Header header;
    header.var = kVar;
    header.size = static_cast<int>(datas.size());
    fwrite(&header, sizeof(header), 1, fp);

    for (const auto& data : datas)
    {
        auto& name = data.first;
        // ���O�̕ۑ�
        int size = static_cast<int>(name.size());
        fwrite(&size, sizeof(size), 1, fp);
        fwrite(name.data(), size * sizeof(wchar_t), 1, fp);

        // ��ނ̕ۑ�
        auto& type = data.second.type;
        fwrite(&(type), sizeof(type), 1, fp);
        // �p�X�̕ۑ�
        auto& path = data.second.path;
        size = static_cast<int>(path.size());
        fwrite(&size, sizeof(size), 1, fp);
        fwrite(path.data(), size * sizeof(wchar_t), 1, fp);
    }

    fclose(fp);
}

std::vector<std::wstring> Split(const std::wstring& str, const char del)
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