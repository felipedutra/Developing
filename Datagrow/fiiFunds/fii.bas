Attribute VB_Name = "Módulo1"
Sub Atualizar()
Attribute Atualizar.VB_ProcData.VB_Invoke_Func = " \n14"
'
' Atualizar Macro
'

'
    ActiveWorkbook.Worksheets("Fiagros").ListObjects("Tabela1").Sort.SortFields. _
        Clear
    ActiveWorkbook.Worksheets("Fiagros").ListObjects("Tabela1").Sort.SortFields. _
        Add2 Key:=Range("Tabela1[[#All],[Código]]"), SortOn:=xlSortOnValues, Order _
        :=xlAscending, DataOption:=xlSortNormal
    With ActiveWorkbook.Worksheets("Fiagros").ListObjects("Tabela1").Sort
        .Header = xlYes
        .MatchCase = False
        .Orientation = xlTopToBottom
        .SortMethod = xlPinYin
        .Apply
    End With
    Sheets("Crédito").Select
    ActiveWorkbook.Worksheets("Crédito").ListObjects("Tabela2").Sort.SortFields. _
        Clear
    ActiveWorkbook.Worksheets("Crédito").ListObjects("Tabela2").Sort.SortFields. _
        Add2 Key:=Range("Tabela2[[#All],[Código]]"), SortOn:=xlSortOnValues, Order _
        :=xlAscending, DataOption:=xlSortNormal
    With ActiveWorkbook.Worksheets("Crédito").ListObjects("Tabela2").Sort
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
        SortFields.Add2 Key:=Range("Tabela3[[#All],[Código]]"), SortOn:= _
        xlSortOnValues, Order:=xlAscending, DataOption:=xlSortNormal
    With ActiveWorkbook.Worksheets("Gestora Independente").ListObjects("Tabela3"). _
        Sort
        .Header = xlYes
        .MatchCase = False
        .Orientation = xlTopToBottom
        .SortMethod = xlPinYin
        .Apply
    End With
    Sheets("Gestora Independente e Crédito").Select
    ActiveWorkbook.Worksheets("Gestora Independente e Crédito").ListObjects( _
        "Tabela4").Sort.SortFields.Clear
    ActiveWorkbook.Worksheets("Gestora Independente e Crédito").ListObjects( _
        "Tabela4").Sort.SortFields.Add2 Key:=Range("Tabela4[[#All],[Código]]"), _
        SortOn:=xlSortOnValues, Order:=xlAscending, DataOption:=xlSortNormal
    With ActiveWorkbook.Worksheets("Gestora Independente e Crédito").ListObjects( _
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
