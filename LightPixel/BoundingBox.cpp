�}�
  �  ���e��0    ��4�~ک���O��7��R'����!@�ϱ���( H l����& �s@�gP�}s=ŋ�S�-J��;�n�
���o����|��xLT-�F��ۅg�z��~2��@
�{�QP�|<��1����O��f�f�\
��\n�v@�����`�.���f
e<w(���ϗ�upIE<޻��$�:36���F��F)|�������Oò�)d'R�����,c��q� �+v��Zx<&z�%,�d��ny}�v���b1���͝���f�之B,)��i�$B����ȱQ�<����N��h"<�g�؅�|�p��?8��]Qh2�^ +)�U��G|��e��v{�zp��Y>���᰻��X������b���bBr�Տ��X78�n1Kl$���7#�:27w���#r��+oN&�GE̿T1Y]M�9�5� ��;p��2��`Rֱ�lX�ǉ(M9Y[��,���S�n���l��E���WDԤ��0�~��$�|���׼7����}J���D�hXܽx^ �P�bhh�ci0��$��'�(�.���/x�3p|]�@>(U�CUZ���4�<:qd���@R;�����`]�8�J�iL�y�+����G�b ���H��<�1m;�gf�E�sIs�]��i���v;5�ҢZ����mfp~��6J����H;"���'��
>5>V���&��r��MFT2 ��G( _  �9�O1�vې9��c���}�S�@L���&�����J���jTs��_X�1&z$95o�瘀Q��R�5�ql�B�DRM@����Z!�*�b���!���{��xPW(NxyV��ܸ��#EY'p�%��/��!X�i�4�oLju�"��j�G}w_8>�hUʊ��_�1���#����T�%1�H�-#3���5���]z#����R:�5��Y���;�\ΰP%5�O�fFR�uޗ0O&�'�@�`ysDɋ�/�Q*�w!=Z���U����y�float minZ = std::min(mMin[2], box.mMin[2]);
	float maxX = std::max(mMax[0], box.mMax[0]);
	float maxY = std::max(mMax[1], box.mMax[1]);
	float maxZ = std::max(mMax[2], box.mMax[2]);

	mMin = Vec3(minX, minY, minZ);
	mMax = Vec3(maxX, maxY, maxZ);
	mCenter = Vec3((maxX - minX) / 2, (maxY - minY) / 2, (maxX - minX) / 2);

	mRadius = mCenter.length();
}

Vec3 BoundingBox::Center()
{
	return mCenter;
}

float BoundingBox::Radius()
{
	return mRadius;
}
