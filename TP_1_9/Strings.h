#pragma once
#include <iostream>

//for logging
const std::string PRINT_BUILDER_STRING = "Вызван конструктор ";
const std::string PRINT_COPY_BUILDER_STRING = "Вызван конструктор копирования";
const std::string PRINT_DECONSTRUCTOR_STRING = "Вызван деструктор ";

//defolt string
const std::string MY_NULL_STRING = "Не указано";

//keys for fields
const std::string PLANE_STRING = "Самолет";
const std::string CAR_STRING = "Автомобиль";
const std::string TRAIN_STRING = "Поезд";
const std::string NAME_STRING = "Наименование";
const std::string TYPE_STRING = "Тип";
const std::string VOLUME_WEID_STRING = "Объем груза";
const std::string MAX_LENGT_STRING = "Максимальная длина груза";
const std::string MAX_WIDTH_STRING = "Максимальная ширина груза";
const std::string MAX_HEIGHT_STRING = "Максимальная высота груза";
const std::string TOWN_LIST_STRING = "Список городов:";
const std::string EMPTY_TOWN_LIST_STRING = "Список городов не задан";
const std::string YEAR_RELISE_STRING = "Год релиза";
const std::string MARK_STRING = "Марка";
const std::string MODEL_STRING = "Модель";
const std::string COUNT_WAGONS_STRING = "Количчество вагонов";

//kyes fields for towns
const std::string TOWN_NAME_STRING = "Название города ";
const std::string TOWN_WAY_HOURS_STRING = "Время в пути для города ";
const std::string TOWN_VOLUME_WEID_STRING = "Объем груза для города ";