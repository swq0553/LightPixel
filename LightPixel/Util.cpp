�}�
  �  U��1ʯ�    ���~���O��Ґt�.BK2�*h׭�C���3A@��g�Y�a9��o��}�����А����IIjA<$��#��X��؅�j�
���F:������F:�%�RŁmr'������X��*�e��Dً��� >(+�]�m�K�J�:)�GQK�$��Z��*�+����l!�6�Ђ1K2�������&�\�C�`TD5�<u�o�ߣk���ebLg���W�v*�X�[|q�P�)B�}���9>�1�ئ�g#zԾo8��CN��2dK���}B��4�>w�̝����p��e�5�CJ��<�g�؅�|�p��?8��]Qh2�^ +)�U��G|��e��v{�zp��Y>���᰻��X������b���bBr�Տ��X78�n1Kl$���7#�:27w���#r��+oN&�GE̿T1Y]M�9�5� ��;p��2��`Rֱ�lX�ǉ(M9Y[��,���S�n���tmp.end() - 1);

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
//}