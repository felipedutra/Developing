Attribute VB_Name = "M�dulo1"
Sub Atualizar()
Attribute Atualizar.VB_ProcData.VB_Invoke_Func = " \n14"
'
' Atualizar Macro
'

'
    ActiveWorkbook.Worksheets("Fiagros").ListObjects("Tabela1").Sort.SortFields. _
        Clear
    ActiveWorkbook.Worksheets("Fiagros").ListObjects("Tabela1").Sort.SortFields. _
        Add2 Key:=Range("Tabela1[[#All],[C�digo]]"), SortOn:=xlSortOnValues, Order _
        :=xlAscending, DataOption:=xlSortNormal
    With ActiveWorkbook.Worksheets("Fiagros").ListObjects("Tabela1").Sort
        .Header = xlYes
        .MatchCase = False
        .Orientation = xlTopToBottom
        .SortMethod = xlPinYin
        .Apply
    End With
    Sheets("Cr�dito").Select
    ActiveWorkbook.Worksheets("Cr�dito").ListObjects("Tabela2").Sort.SortFields. _
        Clear
    ActiveWorkbook.Worksheets("Cr�dito").ListObjects("Tabela2").Sort.SortFields. _
        Add2 Key:=Range("Tabela2[[#All],[C�digo]]"), SortOn:=xlSortOnValues, Order _
        :=xlAscending, DataOption:=xlSortNormal
    With ActiveWorkbook.Worksheets("Cr�dito").ListObjects("Tabela2").Sort
        .Header = xlYes
        .MatchCase = False
        .Orientation = xlTopToBottom
        .SortMethod = xlPinYin
        .Apply
    End With
    Sheets("Gestora Independente").Select
    ActiveWorkbook.Worksheets("Gestora Independente").ListObjects("Tabela3").Sort. _
        SortFields.Clear
    ActiveWorkbook.Worksheets("Gestora Independente").ListObjects("Tabela3").Sort. _
        SortFields.Add2 Key:=Range("Tabela3[[#All],[C�digo]]"), SortOn:= _
        xlSortOnValues, Order:=xlAscending, DataOption:=xlSortNormal
    With ActiveWorkbook.Worksheets("Gestora Independente").ListObjects("Tabela3"). _
        Sort
        .Header = xlYes
        .MatchCase = False
        .Orientation = xlTopToBottom
        .SortMethod = xlPinYin
        .Apply
    End With
    Sheets("Gestora Independente e Cr�dito").Select
    ActiveWorkbook.Worksheets("Gestora Independente e Cr�dito").ListObjects( _
        "Tabela4").Sort.SortFields.Clear
    ActiveWorkbook.Worksheets("Gestora Independente e Cr�dito").ListObjects( _
        "Tabela4").Sort.SortFields.Add2 Key:=Range("Tabela4[[#All],[C�digo]]"), _
        SortOn:=xlSortOnValues, Order:=xlAscending, DataOption:=xlSortNormal
    With ActiveWorkbook.Worksheets("Gestora Independente e Cr�dito").ListObjects( _
        "Tabela4").Sort
        .Header = xlYes
        .MatchCase = False
        .Orientation = xlTopToBottom
        .SortMethod = xlPinYin
        .Apply
    End With
    Sheets("Fiagros").Select
    Range("A1").Select
End Sub
