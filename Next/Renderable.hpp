�}�
    |�df�m    ���~Ҷ��O�ӷ��v{ٱѥg2�����/�����!�ٶKv�a*s#���n?y^CZz�UJ5Ѕ�MM
j|Qq��`� l��mݜN�B����z���a��	��H�M6	#���:�y�˛$���%i\XV��e�\��D-�v���(�,�(�[Ԅ�y��ۄ2�RH�ta s�0p10���/�0�8�&����@��
CP	��Z:ef��xj�M�=��F���gƗG�Fd4����NS��j�5��V�9�xK���}B��4�>w�̝����p��e�5�CJ��<�g�؅�|�p��?8��]Qh2�^ +)�U��G|��e��v{�zp��Y>���᰻��X������b���bBr�Տ��X78�n1Kl$���7#�:27w���#r��+oN&�GE̿T1Y]M�9�5� ��;p��2��`Rֱ�lX�ǉ(M9Y[��,���S�n���red_ptr<Technique>  TechniquePtr;
	public:
		Renderable(void);
		~Renderable(void);

		Technique* GetTechnique();
		void SetModelMtrix(Mat4 modelmatrix);
		void Render();
		virtual void DoRender();
		virtual void DoRenderBegin();
		virtual void DoRenderEnd();

		virtual BoundingBox* GetBoundingBox() = 0;
		inline RenderMaterial GetMaterial(){ return mMtl; };
	protected:
		Technique*     mTech;
		RenderMaterial mMtl;
		Mat4           mModelMatrix;
	};
}
#endif