�}�
    C$��7�    ���~�q��?���f4���/3���%(P�RH]H$v�t7�cP�X�Q�̙���r����J�P�Z�u�N�´9K{W����ᵑ
@>x���+"��I�ؽ 	����8���*���2����[��B6���aJoF\�!>���TE���S�<�;D2q�"�r������r�6�Q�>�X`����rAV��囏<�E��;����QT�J�b��|�9��O���F�1���4���C�����g:�m����?�Gˋ�&�^eG��EyG��2�K���}B��4�>w�̝����p��e�5�CJ��<�g�؅�|�p��?8��]Qh2�^ +)�U��G|��e��v{�zp��Y>���᰻��X������b���bBr�Տ��X78�n1Kl$���7#�:27w���#r��+oN&�GE̿T1Y]M�9�5� ��;p��2��`Rֱ�lX�ǉ(M9Y[��,���S�n���tmp.end() - 1);

		return dest;
	}

	std::wstring& Convert(std::wstring& dest, std::string const & src)
	{
		int const wcs_len = MultiByteToWideChar(CP_ACP, 0, src.c_str(), static_cast<int>(src.size()), nullptr, 0);
		std::vector<wchar_t> tmp(wcs_len + 1);
		MultiByteToWideChar(CP_ACP, 0, src.c_str(), static_cast<int>(src.size()), &tmp[0], wcs_len);

		dest.assign(tmp.begin(), tmp.end() - 1);

		return dest;
	}
}