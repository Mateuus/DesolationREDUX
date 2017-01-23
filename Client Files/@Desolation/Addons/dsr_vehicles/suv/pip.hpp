		class RenderTargets /// class for all Picture-in-Picture (PiP)
		{
			class LeftMirror
			{
				renderTarget = "rendertarget0"; /// what texture is going to be used, it should be mapped in model like #(argb,256,512,1)r2t(rendertarget0,1.0)
				class CameraView1
				{
					pointPosition		= "pip0_pos"; 	/// memory point of PiP origin
					pointDirection		= "pip0_dir"; 	/// memory point of PiP direction
					renderQuality 		= 2;			/// what quality should the PiP be
					renderVisionMode 	= 0;			/// zero means standard vision
					fov 				= 0.7;			/// what is the angle of the PiP field of view
				};
			};
			class RearCam
			{
				renderTarget = "rendertarget1"; /// what texture is going to be used, it should be mapped in model like #(argb,256,512,1)r2t(rendertarget0,1.0)
				class CameraView1
				{
					pointPosition		= "pip1_pos"; 	/// memory point of PiP origin
					pointDirection		= "pip1_dir"; 	/// memory point of PiP direction
					renderQuality 		= 2;			/// what quality should the PiP be
					renderVisionMode 	= 0;			/// zero means standard vision
					fov 				= 0.7;			/// what is the angle of the PiP field of view
				};
			};
			class FrontCam	/// rendering of PiPs is shared, it is best to have one for all sources, this is just an example
			{
				renderTarget = "rendertarget2";
				class CameraView1
				{
					pointPosition		= "pip2_pos";
					pointDirection		= "pip2_dir";
					renderQuality 		= 2;
					renderVisionMode 	= 0;
					fov 				= 0.7;
				};
			};
		};
