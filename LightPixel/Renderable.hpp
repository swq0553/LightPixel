�}"
  �  5��É�8    ��	�~:�q��O��ȌVwv�k5�R��:�����1�uT��хo;�(�P0��'Z��@S�X��ŋ+��Λ��ݼv?k���,�i�I��qt�;��y;���Aj⮊a�*t^=l+�h�����PBb�J�[²��2���� x
A�)�v0-���tsh����}!�j��.� �E�i!�0'Q���4�7�sFU����2�Q�x��5#D&��t4c�����}�z�Qr������/�>��@�nK*~+���}k�V��>B�K�9�xK���}B��4�>w�̝����p��e�5�CJ��<�g�؅�|�p��?8��]Qh2�^ +)�U��G|��e��v{�zp��Y>���᰻��X������b���bBr�Տ��X78�n1Kl$���7#�:27w���#r��+oN&�GE̿T1Y]M�9�5� ��;p��2��`Rֱ�lX�ǉ(M9Y[��,���S�n���ual void DoRenderEnd();

	virtual BoundingBoxPtr GetBoundingBox() = 0;
	inline RenderMaterial GetMaterial(){ return mMtl; };
protected:
	RenderTechniquePtr     mTech;
	RenderMaterial         mMtl;
	Mat4                   mModelMatrix;
};

