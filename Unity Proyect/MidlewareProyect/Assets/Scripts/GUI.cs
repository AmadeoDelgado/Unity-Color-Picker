using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

/// <summary>
/// Class that controls the interface of the tool
/// </summary>
public class ColorInterface : EditorWindow
{
 
    Color32 pickedColor = Interface.InitializeWrap();

    //analogous colors
    Color32 analogousColor = Color.white;
    Color32 analogousColor2 = Color.white;
   
    //inverse colors
    Color32 inverse = Color.white;

    [MenuItem("Window/ColorTool")]
    public static void windowVisible()
    {
       GetWindow<ColorInterface>("Color Tool");
       ColorInterface window = (ColorInterface)EditorWindow.GetWindow(typeof(ColorInterface));
    }
    private void OnGUI()
    {
             
        EditorGUILayout.Separator();     
        pickedColor = EditorGUILayout.ColorField("Color Selector", pickedColor);
        EditorGUILayout.Separator();
        GUILayout.Label("Analogous Colors");
        GUI.color = analogousColor;
        GUILayout.Box("    ");
        GUI.color = analogousColor2;
        GUILayout.Box("    ");
        GUI.color = pickedColor;
        GUILayout.Box("    ");
       

        EditorGUILayout.Separator();
        GUILayout.Label("Oposite Color");
        GUI.color = inverse;
        GUILayout.Box("    ");
        EditorGUILayout.Separator();

        GUI.color = Color.white;

        if (GUILayout.Button("Generate inverse color"))
        { 
            inverse = Interface.InverseColorsWrap(pickedColor);          
        }

        if (GUILayout.Button("Generate Analogous colors"))
        {
            analogousColor = Interface.AnlagousColorWrap(pickedColor,1);
            analogousColor2 = Interface.AnlagousColorWrap(pickedColor, 2);           
        }       
        EditorGUILayout.Separator();                     
    }
}
